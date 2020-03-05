#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "Player.h"
#include "FrameTimer.h"
#include "Brick.h"

class Game
{
public:
	Game(class GameWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	GameWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	/********************************/
	/*  User Variables              */
	/********************************/
	Player p;
	Brick b;
	Brick c;
	Brick d;
};