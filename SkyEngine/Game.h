#pragma once

#include "Graphics.h"
#include "Brick.h"
#include "Ball.h"
#include "FrameTimer.h"
#include "Paddle.h"

class Game
{
public:
	Game(class GameWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void Update();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	GameWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	RectF screenRect;
	/********************************/
	/*  User Variables              */
	/********************************/
	Brick brick;
	Ball ball;
	Paddle paddle;
};