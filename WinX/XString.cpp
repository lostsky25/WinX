#include "XString.h"
//
//XString::XString() {
//
//}
//
//XString::XString(const char* s) : size(strlen(s) + 1), data(new (std::nothrow) char[size]) {
//	if (data) {
//		++use_count;
//		std::copy(s, s + size, data);
//	}
//}
//
//XString::XString(const XString& obj) : size(strlen(obj.data) + 1), data(new char[size]) {
//	if (data) {
//		++use_count;
//		std::copy(obj.data, obj.data + size, data);
//	}
//}
//
//size_t XString::getSize() {
//	return size;
//}
//
//char* XString::getData() {
//	return data;
//}
//
//XString::operator char* () {
//	return data;
//}
//
//XString& XString::operator=(const char* other)
//{
//	XString tmp(other);
//	swap(tmp, *this);
//	return *this;
//}
//
//void swap(XString& first, XString& second)
//{
//	using std::swap;
//	std::swap(first.data, second.data);
//	std::swap(first.size, second.size);
//}
//
//
//std::ostream& operator<<(std::ostream& os, XString& str) {
//	if (!str.getData())
//		return (os << "");
//	os << str.getData();
//	return os;
//}