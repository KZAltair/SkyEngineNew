#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brick({50.0f, 50.0f})
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
	brick.Draw(gfx, Color(120, 120, 120));
}

//TODO
//Add Vector class with template
//Add Rectangle class with template
//Add Frametimer
//Add Surface class
//Add Animation class
//Add Text class
//Add WinGDI to read bitmap files: png, jpeg, bmp with alpha
//Add sound class with XAUDIO from Chili
