#include "Player.h"

Player::Player(const Vec2& pos, float speed, int width, int height, Color c)
	:
	pos(pos),
	speed(speed),
	width(width),
	height(height),
	color(c)
{
}

void Player::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, width, height, color);
}

void Player::Update(const Keyboard& kbd, float dt)
{
	vel = { 0.0f, 0.0f };
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x = -1.0f * speed;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x = 1.0f * speed;
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		vel.y = -1.0f * speed;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		vel.y = 1.0f * speed;
	}
	pos += vel * dt;
}

bool Player::DoCollision(const Platform& p)
{
	bool collided = false;
	RectF rect = GetRect();
	if (rect.IsOverlappingWith(p.GetRect()))
	{
		if (prevPos.x + width <= p.GetRect().left)
		{
			pos.x -= rect.right - p.GetRect().left;
			collided = true;
		}
		else if (prevPos.x >= p.GetRect().right)
		{
			pos.x += p.GetRect().right - rect.left;
			collided = true;
		}
		else if (prevPos.x + width >= p.GetRect().left && prevPos.x <= p.GetRect().right && prevPos.y + height <= p.GetRect().top)
		{
			pos.y -= rect.bottom - p.GetRect().top;
			collided = true;
		}
		else if (prevPos.x + width >= p.GetRect().left && prevPos.x <= p.GetRect().right && prevPos.y >= p.GetRect().bottom)
		{
			pos.y += p.GetRect().bottom - rect.top;
			collided = true;
		}
		
	}
	prevPos = pos;
	return collided;
}

RectF Player::GetRect() const
{
	return RectF(pos, width, height);
}

Vec2 Player::GetCenter() const
{
	Vec2 position;
	position.x = pos.x + width / 2;
	position.y = pos.y + height / 2;
	return position;
}
