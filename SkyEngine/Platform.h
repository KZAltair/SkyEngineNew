#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Player.h"

class Platform
{
public:
	Platform(const Vec2& pos, int width, int height, Color c);
	Platform(const Vec2& pos, RectF srcRect, const RectI& clip);
	void Draw(Graphics& gfx);
	void DrawSprite(Graphics& gfx);
	bool DoCollision(Player& p);
	RectF GetRect() const;
	RectF GetSpriteRect() const;
	Vec2 GetCenter() const;

private:
	Surface surf;
	Vec2 pos;
	int width;
	int height;
	Color color;
	RectF rect;
	RectI clip;
};
