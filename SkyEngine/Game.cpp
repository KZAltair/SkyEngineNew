#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	Update();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::Update()
{
	//Do update game stuff here
}

void Game::ComposeFrame()
{
	//Do graphics stuff here
}