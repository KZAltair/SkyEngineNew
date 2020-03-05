#include "Player.h"
#include "Graphics.h"
#include <assert.h>

Player::Player(const RectI& bounds)
	:
	rect(bounds),
	surf(L"Images\\test01.png")
{
}

void Player::Draw(Graphics& gfx)
{
	assert(pos.x >= 0.0f);
	assert(pos.x <= Graphics::ScreenWidth);
	assert(pos.y >= 0.0f);
	assert(pos.y <= Graphics::ScreenHeight);
	gfx.DrawSp(pos.x, pos.y, rect, surf);
}

void Player::DrawRect(Graphics& gfx)
{
	assert(pos.x >= 0.0f);
	assert(pos.x <= Graphics::ScreenWidth);
	assert(pos.y >= 0.0f);
	assert(pos.y <= Graphics::ScreenHeight);
	for (int y = GetRect().top; y < GetRect().top + (GetRect().bottom - GetRect().top); y++)
	{
		for (int x = GetRect().left; x < GetRect().left + (GetRect().right - GetRect().left); x++)
		{
			gfx.PutPixel(x, y, Color(255, 0, 0));
		}
	}
}

void Player::Update(float dt, const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x += -5500.0f * dt;
	}
	else
	{
		vel.x = 0.0f;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x = 5500.0f * dt;
	
	}
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		isPressed = true;
	}
	if (isPressed)
	{
		if (vel.y == 0.0f)
		{
			vel.y = -50.0f;
		}
	}
	vel.y += 20.0f * dt;
	pos += vel * dt;
	if (vel.x > 10.0f)
	{
		vel.x = 10.0f;
	}
	if (vel.x < -10.0f)
	{
		vel.x = -10.0f;
	}
	if (vel.y > 100.0f)
	{
		vel.y = 100.0f;
	}
	if (vel.y < -100.0f)
	{
		vel.y = -100.0f;
	}
	
	
}

void Player::DoCollision(const RectI& other)
{
	rect = GetRect();

	if (rect.left <= other.right && rect.top + rect.GetHeight() > other.top)
	{
		pos.x = other.right;
		vel.x = 0;
	}
	else if (rect.bottom >= other.top && rect.left + rect.GetWidth() >= other.left && rect.right - rect.GetWidth() <= other.right)
	{
		pos.y = other.top - rect.GetHeight();
		vel.y = 0;
		isPressed = false;
	}
	else if (rect.right >= other.left && rect.top + rect.GetHeight() >= other.top)
	{
		pos.x = other.left-rect.GetWidth();
		vel.x = 0;
	}
	else if (rect.top <= other.bottom && rect.left + rect.GetWidth() >= other.left && rect.right - rect.GetWidth() <= other.right)
	{
		pos.y = other.bottom + rect.GetHeight();
	}
}

RectI Player::GetRect() const
{
	return RectI({(int)pos.x, (int)pos.y}, 32, 32);
}
