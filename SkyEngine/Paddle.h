#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Graphics.h"
#include "Mouse.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(const Mouse& mouse, float dt);
	bool DoBallCollision(Ball& ball);
	bool DoWallCollision(const RectF& walls);
	RectF GetRect() const;

private:
	Vec2 pos;
	static constexpr float width = 80.0f;
	static constexpr float height = 20.0f;
};