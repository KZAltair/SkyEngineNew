#pragma once

#include "Graphics.h"
#include "Platform.h"
#include "Player.h"
#include "FrameTimer.h"

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
	/********************************/
	/*  User Variables              */
	/********************************/
	Platform platform;
	Player p;
};