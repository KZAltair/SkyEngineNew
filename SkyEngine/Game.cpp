#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	surf(L"Images\\test01.png")
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
	gfx.DrawSp(100, 100, {0,32,0,32}, surf);
}