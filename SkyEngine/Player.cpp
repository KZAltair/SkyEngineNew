#include "Player.h"
#include "Graphics.h"
#include <assert.h>

Player::Player(const RectI& bounds)
	:
	rect(bounds),
	surf(L"Images\\test01.png")
{
	pos.x = static_cast<float>(Graphics::ScreenWidth / 2);
	pos.y = static_cast<float>(Graphics::ScreenHeight / 2);
}

void Player::Draw(Graphics& gfx)
{
	assert(pos.x >= 0.0f);
	assert(pos.x <= Graphics::ScreenWidth);
	assert(pos.y >= 0.0f);
	assert(pos.y <= Graphics::ScreenHeight);
	gfx.DrawSp(pos.x, pos.y, rect, surf);
}

void Player::Update(float dt, const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x = -maxSpeed;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x = maxSpeed;
	}
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		if (pos.y >= Graphics::ScreenHeight / 2)
		{
			vel.y = -maxSpeed;
		}
	}
	pos.x += vel.x * dt + 1.0f / gravity * dt * dt;
	pos.y += vel.y * dt + 1.0f / gravity * dt * dt;
	if (pos.y > Graphics::ScreenHeight / 2)
	{
		vel.y = 0.0f;
	}
	else
	{
		vel.y += gravity * dt;
	}
	if (vel.x > 0.0f)
	{
		vel.x -= airFriction * dt;
	}
	else if (vel.x < 0.0f)
	{
		vel.x += airFriction * dt;
	}
	else
	{
		vel.x = 0.0f;
	}
	
	
}
