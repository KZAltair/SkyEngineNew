#include "Platform.h"

Platform::Platform(const Vec2& pos, int width, int height, Color c)
	:
	pos(pos),
	width(width),
	height(height),
	color(c)
{
}

void Platform::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, width, height, color);
}

RectF Platform::GetRect() const
{
	return RectF(pos, width, height);
}

Vec2 Platform::GetCenter() const
{
	Vec2 position;
	position.x = pos.x + width / 2;
	position.y = pos.y + height / 2;
	return position;
}
