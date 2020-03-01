#pragma once

#include "Graphics.h"

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
	/********************************/
	/*  User Variables              */
	/********************************/
};