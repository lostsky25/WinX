#pragma once


#include <condition_variable>
#include <functional>
#include <vector>
#include <thread>
#include <future>
#include <queue>

class XThreadPool {
public:
	using Task = std::function<void()>;

	explicit XThreadPool(std::size_t);

	void enqueue(Task);

	~XThreadPool();

private:
	std::vector<std::future<void>> mThreads;
	std::condition_variable mEventVar;
	std::mutex mEventMutex;
	bool mStopping = false;
	std::queue<Task> mTasks;

	void start(std::size_t);
	void stop() noexcept;
};