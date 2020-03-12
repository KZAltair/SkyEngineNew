#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Keyboard.h"
//#include "Platform.h"

class Player
{
public:
	Player(const Vec2& pos, float speed, int width, int height, Color c);
	void Draw(Graphics& gfx);
	void Update(const Keyboard& kbd, float dt);
	//bool DoCollision(const Platform& p);
	void AdjustLeftPosition(const RectF& p);
	void AdjustRightPosition(const RectF& p);
	void AdjustTopPosition(const RectF& p);
	void AdjustBottomPosition(const RectF& p);
	Vec2 GetPosition() const;
	Vec2 GetVelocity() const;
	int GetWidth() const;
	int GetHeight() const;
	Vec2 GetPrevPos() const;
	RectF GetRect() const;
	Vec2 GetCenter() const;

public:
	Vec2 vel;
	Vec2 pos;
	Vec2 prevPos;
	bool isPressed = false;
private:
	
	float speed;
	static constexpr float jumpSpeed = 1000.0f;
	int width;
	int height;
	Color color;
	float gravity = 9.8f;
};
