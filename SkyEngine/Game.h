#pragma once

#include "Graphics.h"
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
	void Update();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	GameWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Brick brick;
};