#pragma once

#include "Colors.h"
#include "Rect.h"
#include <vector>
#include <string>

class Surface
{
public:
	Surface(const std::wstring& filename);
	Surface(int width, int height);
	Surface(const Surface&);
	Surface& operator=(const Surface& rhs);
	~Surface();

	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
	void BakeAlpha();

private:
	Color* pPixels = nullptr;
	int width = 0;
	int height = 0;
};