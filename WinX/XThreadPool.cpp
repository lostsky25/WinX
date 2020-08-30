#include "XThreadPool.h"

XThreadPool::XThreadPool(std::size_t numThreads) {
	start(numThreads);
}

void XThreadPool::enqueue(XThreadPool::Task task) {
	{
		std::unique_lock<std::mutex> lock(mEventMutex);
		mTasks.emplace(std::move(task));
	}

	mEventVar.notify_one();
}

XThreadPool::~XThreadPool() {
	stop();
}

void XThreadPool::start(std::size_t numThreads) {
	for (auto i = 0u; i < numThreads; ++i)
	{
		mThreads.emplace_back(std::async([=] {
			while (true) {
				Task task;

				{
					std::unique_lock<std::mutex> lock(mEventMutex);
					mEventVar.wait(lock, [=] { return mStopping || !mTasks.empty(); });

					if (mStopping && mTasks.empty()) {
						break;
					}

					task = std::move(mTasks.front());
					mTasks.pop();
				}

				task();
			}
			}));
	}
}

void XThreadPool::stop() noexcept {
	{
		std::unique_lock <std::mutex> lock(mEventMutex);
		mStopping = true;
	}

	mEventVar.notify_all();

	for (auto& thread : mThreads)
	{
		thread.get();
	}

}