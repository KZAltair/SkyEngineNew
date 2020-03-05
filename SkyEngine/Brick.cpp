#include "Brick.h"
#include "Graphics.h"
#include <assert.h>

Brick::Brick(const RectI& bounds, const Vec2& pos)
	:
	rect(bounds),
	surf(L"Images\\brick.png"),
	pos(pos)
{
}

void Brick::Draw(Graphics& gfx)
{
	assert(pos.x >= 0.0f);
	assert(pos.x <= Graphics::ScreenWidth);
	assert(pos.y >= 0.0f);
	assert(pos.y <= Graphics::ScreenHeight);
	gfx.DrawSp(pos.x, pos.y, rect, surf);
}

RectI Brick::GetRect() const
{
	return RectI({ (int)pos.x, (int)pos.y }, 64, 64);
}