#pragma once
#include "Rect.h"
#include "Surface.h"
#include "Vec2.h"
#include "Keyboard.h"

class Player
{
public:
	Player(const RectI& bounds);
	void Draw(class Graphics& gfx);
	void DrawRect(class Graphics& gfx);
	void Update(float dt, const Keyboard& kbd);
	void DoCollision(const RectI& other);
	RectI GetRect() const;
private:
	Surface surf;
	RectI rect;
	Vec2 pos = { 0.0f, 0.0f };
	Vec2 vel = { 0.0f, 0.0f };
	float gravity = 120.0f;
	float maxSpeed = 100.0f;
	float airFriction = 100.0f;
	bool isPressed = false;
};
