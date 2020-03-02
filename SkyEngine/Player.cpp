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
	vel = { 0.0f, 0.0f };
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x = -1.0f;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x = 1.0f;
	}
	pos.x += vel.x * maxSpeed * dt;
}
