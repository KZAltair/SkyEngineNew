#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"

class Platform
{
public:
	Platform(const Vec2& pos, int width, int height, Color c);
	void Draw(Graphics& gfx);
	RectF GetRect() const;
	Vec2 GetCenter() const;

private:
	Vec2 pos;
	int width;
	int height;
	Color color;
};
