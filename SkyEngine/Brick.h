#pragma once
#include "Rect.h"
#include "Surface.h"
#include "Vec2.h"

class Brick
{
public:
	Brick(const RectI& bounds, const Vec2& pos);
	void Draw(class Graphics& gfx);
	RectI GetRect() const;
private:
	Surface surf;
	RectI rect;
	Vec2 pos = { 0.0f, 0.0f };
};