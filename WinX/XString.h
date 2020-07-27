#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <Windows.h>
#include <atomic>

#pragma warning (disable : 4996)

class impl_xstring {
	wchar_t* data;
	size_t size;
	size_t useCount;

	friend class XString;
};

class XString
{
	impl_xstring* impl;
public:
	XString() {
		impl = new impl_xstring();
		++impl->useCount;
	}

	XString(const XString& s) : impl(s.impl) {
		++impl->useCount;
		//std::cout << "0x" << impl << " " << impl->useCount << std::endl;
	}
	XString(const wchar_t* s) {
		impl = new impl_xstring();
		++impl->useCount;
		//std::cout << "0x" << impl << " " << impl->useCount << std::endl;
		impl->size = lstrlen(s) +1;
		impl->data = new wchar_t[impl->size + 1];
		wcscpy_s(impl->data, impl->size, s);
	}

	size_t getSize() const {
		return impl->size;
	}

	wchar_t* getData() const {
		return impl->data;
	}

	XString& operator=(const WCHAR* other)
	{
		XString tmp = other;
		std::swap(*this, tmp);
		return *this;
	}

	~XString() {
		--impl->useCount;
		//std::cout << "0x" << impl << " " << impl->useCount << std::endl;
		if (!impl->useCount) {
			//delete impl;
		}
	}
};