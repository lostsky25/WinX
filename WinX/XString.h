#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <Windows.h>

#pragma warning (disable : 4996)

class XString
{
public:

	LPCWSTR data;
	size_t size;
	size_t capacity;
	size_t use_count;

	std::allocator<WCHAR> al;

	XString() = default;
	
	XString(LPCWSTR s) {
		try
		{
			size = lstrlen(s) + 1;
			data = al.allocate(size);
			if (data) {
				++use_count;
				//wcscpy((wchar_t*)data, (wchar_t*)s);
				data = s;
			}	
		}
		catch (const std::exception& e)
		{
			OutputDebugStringA(e.what());
		}
	}

	XString(const XString& obj) : size(lstrlen(obj.data) + 1), data(new WCHAR[size]) {
		try
		{
			size = lstrlen(obj.data) + 1;
			data = al.allocate(size);
			if (data) {
				++use_count;
				//std::copy(obj.data, obj.data + size, data);
				//wcscpy((wchar_t*)data, (wchar_t*)obj.data);
				data = obj.data;
			}
		}
		catch (const std::exception& e)
		{
			OutputDebugStringA(e.what());
		}
	}

	size_t getSize() {
		return size;
	}

	LPCWSTR getData() {
		return data;
	}

	operator LPCWSTR () {
		return data;
	}

	XString& operator=(const LPCWSTR other)
	{
		XString tmp(other);
		swap(tmp, *this);
		return *this;
	}

	friend void swap(XString& first, XString& second)
	{
		using std::swap;
		std::swap(first.data, second.data);
		std::swap(first.size, second.size);
	}
	
	


protected:
	friend class XButton;
};
//
//std::ostream& operator<<(std::ostream& os, XString& str) {
//	if (!str.getData())
//		return (os << "");
//	os << str.getData();
//	return os;
//}