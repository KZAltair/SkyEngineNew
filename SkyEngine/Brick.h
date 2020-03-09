#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Vec2& pos);
	void Draw(Graphics& gfx, Color c);
	void Update(float dt);

private:
	static constexpr int brickWidth = 50;
	static constexpr int brickHeight = 25;
	Vec2 pos;
};
