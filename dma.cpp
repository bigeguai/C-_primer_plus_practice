#include <cstring>
#include "dma.h"
using namespace std;
baseDMA::baseDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	strcpy_s(label, std::strlen(l), l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	strcpy_s(label, std::strlen(rs.label), rs.label);
	rating = rs.rating;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) : baseDMA(l, r)
{
	strcpy_s(color, COL_LEN - 1, c);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseDMA(rs)
{
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r)
	: baseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
	: baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: baseDMA(hs) // invoke base class copy constructor
{
	style = new char[std::strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs); // copy base portion
	delete[] style;         // prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	strcpy(style, hs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}