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
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//Do update game stuff here
}

void Game::ComposeFrame()
{
	//Do graphics stuff here
}