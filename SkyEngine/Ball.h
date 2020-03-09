#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& pos, const Vec2& vel);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool DoCollision(const RectF& screenRect);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;

private:
	Vec2 pos;
	Vec2 vel;
	Surface surf;
	static constexpr float radius = 20.0f;
};
