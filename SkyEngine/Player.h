#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Keyboard.h"
#include "Platform.h"

class Player
{
public:
	Player(const Vec2& pos, float speed, int width, int height, Color c);
	void Draw(Graphics& gfx);
	void Update(const Keyboard& kbd, float dt);
	bool DoCollision(const Platform& p);
	RectF GetRect() const;
	Vec2 GetCenter() const;

private:
	Vec2 pos;
	Vec2 vel;
	Vec2 prevPos;
	float speed;
	int width;
	int height;
	Color color;
};
