#include "Player.h"

Player::Player(const Vec2& pos, float speed, int width, int height, Color c)
	:
	pos(pos),
	speed(speed),
	width(width),
	height(height),
	color(c)
{
	vel = { 0.0f, 0.0f };
}

void Player::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, width, height, color);
}

void Player::Update(const Keyboard& kbd, float dt)
{
	vel.x = 0.0f;
	if (vel.y >= jumpSpeed)
	{
		vel.y = jumpSpeed;
	}
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
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		isPressed = true;
	}
	if (isPressed)
	{
		if (vel.y != 0.0f)
		{
			vel.y += gravity;
		}
		else
		{
			vel.y = -1.0f * jumpSpeed;
		}
	}
	else
	{
		vel.y += gravity;
	}

	pos += vel * dt;
}

/*bool Player::DoCollision(const Platform& p)
{
	bool collided = false;
	RectF rect = GetRect();
	if (rect.IsOverlappingWith(p.GetRect()))
	{
		OutputDebugStringA("Collided\n");
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
			isPressed = false;
			vel.y = 0.0f;
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
*/

void Player::AdjustLeftPosition(const RectF& p)
{
	RectF rect = GetRect();
	pos.x -= rect.right - p.left;
}

void Player::AdjustRightPosition(const RectF& p)
{
	RectF rect = GetRect();
	pos.x += p.right - rect.left;
}

void Player::AdjustTopPosition(const RectF& p)
{
	RectF rect = GetRect();
	pos.y -= rect.bottom - p.top;
	isPressed = false;
	vel.y = 0.0f;
}

void Player::AdjustBottomPosition(const RectF& p)
{
	RectF rect = GetRect();
	pos.y += p.bottom - rect.top;
}

Vec2 Player::GetPosition() const
{
	return pos;
}

Vec2 Player::GetVelocity() const
{
	return vel;
}

int Player::GetWidth() const
{
	return width;
}

int Player::GetHeight() const
{
	return height;
}

Vec2 Player::GetPrevPos() const
{
	return prevPos;
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
