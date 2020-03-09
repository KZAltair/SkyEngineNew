#include "Brick.h"

Brick::Brick(const Vec2& pos)
	:
	pos(pos)
{
}

void Brick::Draw(Graphics& gfx, Color c)
{
	gfx.DrawRect((int)pos.x, (int)pos.y, brickWidth, brickHeight, c);
}

void Brick::Update(float dt)
{
}
