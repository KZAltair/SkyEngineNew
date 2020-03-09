#include "Ball.h"
#include <assert.h>

Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	pos(pos),
	vel(vel),
	surf(L"Images\\ball.png")
{
}

void Ball::Draw(Graphics& gfx)
{
	//assert(pos.x <= 0);
	//assert(pos.x >= int(Graphics::ScreenWidth));
	//assert(pos.y <= 0);
	//assert(pos.y >= int(Graphics::ScreenHeight));
	gfx.DrawSp(GetRect(), surf);
	//gfx.DrawRect(GetRect().left, GetRect().top, GetRect().GetWidth(), GetRect().GetHeight(), Color(255, 0, 0));
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::DoCollision(const RectF& screenRect)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < screenRect.left)
	{
		pos.x += screenRect.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > screenRect.right)
	{
		pos.x -= rect.right - screenRect.right;
		ReboundX();
		collided = true;
	}
	if (rect.top < screenRect.top)
	{
		pos.y += screenRect.top - rect.top;
		ReboundY();
		collided = true;
		
	}
	else if (rect.bottom > screenRect.bottom)
	{
		pos.y -= rect.bottom - screenRect.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}
