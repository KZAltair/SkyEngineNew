#include "Platform.h"

Platform::Platform(const Vec2& pos, int width, int height, Color c)
	:
	pos(pos),
	width(width),
	height(height),
	color(c),
	surf(L"Images\\brick.png"),
	rect(rect),
	clip(clip)
{
}

Platform::Platform(const Vec2& pos, RectF srcRect, const RectI& clip)
	:
	pos(pos),
	rect(srcRect),
	clip(clip),
	surf(L"Images\\brick.png")
{
}

void Platform::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, width, height, color);
}

void Platform::DrawSprite(Graphics& gfx)
{
	gfx.DrawSprite(pos.x, pos.y, rect, clip, surf);
}

bool Platform::DoCollision(Player& p)
{
	bool collided = false;
	RectF rect = GetSpriteRect();
	RectF playerRect = p.GetRect();
	if (playerRect.IsOverlappingWith(rect))
	{
			if ((p.prevPos.x + p.GetWidth() - 5) <= rect.left)
			{
				p.AdjustLeftPosition(rect);
				collided = true;
			}
			else if ((p.prevPos.x + 5) >= rect.right)
			{
				p.AdjustRightPosition(rect);
				collided = true;
			}
			else if (p.prevPos.x + p.GetWidth() >= rect.left && p.prevPos.x <= rect.right && (p.prevPos.y + p.GetHeight()-5) <= rect.top)
			{
				p.AdjustTopPosition(rect);
				p.isPressed = false;
				p.vel.y = 0.0f;
				collided = true;
			}
			else if (p.prevPos.x + p.GetWidth() >= rect.left && p.prevPos.x <= rect.right && (p.prevPos.y + 5) >= rect.bottom)
			{
				p.AdjustBottomPosition(rect);
				collided = true;
			}

		}
		p.prevPos = p.pos;

	return collided;
}

void Platform::Update(float dt, const Player& p, RectI& rect)
{
	if (p.GetRect().right > rect.GetWidth() / 2)
	{
		pos.x -= cameraMovementSpeed * dt;
	}
}

RectF Platform::GetRect() const
{
	return RectF(pos, width, height);
}

RectF Platform::GetSpriteRect() const
{
	return RectF(pos, rect.GetWidth(), rect.GetHeight());
}

Vec2 Platform::GetCenter() const
{
	Vec2 position;
	position.x = pos.x + width / 2;
	position.y = pos.y + height / 2;
	return position;
}
