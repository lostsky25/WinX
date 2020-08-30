#include "XMainWindow.h"
#define XDebug

#include "XThread.h"
#include "XThreadPool.h"

XMainWindow::XMainWindow(XParams xParams) {
	Application = new XApplication(xParams);
	Application->setMaximumSize(215, 135);
	Application->setMinimumSize(215, 135);

	XThreadPool pool(3);

	pool.enqueue([=] {
		while (true) {
			OutputDebugStringA("Th1\n");
			std::chrono::milliseconds(500);
		}
		});

	pool.enqueue([=] {
		while (true) {
			OutputDebugStringA("Th2\n");
			std::chrono::milliseconds(500);
		}
		});

	Application->windowUpdate();
}