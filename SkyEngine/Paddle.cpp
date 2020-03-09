#include "Paddle.h"

Paddle::Paddle(const Vec2& pos)
	:
	pos(pos)
{
}

void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, width, height, Color(200, 100, 100));
}

void Paddle::Update(const Mouse& mouse, float dt)
{
	pos.x = mouse.GetPosX();
}

bool Paddle::DoBallCollision(const RectF& ballRect)
{
	return false;
}

bool Paddle::DoWallCollision(const RectF& walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left;
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		collided = true;
	}
	return collided;
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, width, height);
}
