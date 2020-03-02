#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	p({0,32,0,32})
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
	float dt = ft.Mark();
	//Do update game stuff here
	p.Update(dt, wnd.kbd);

}

void Game::ComposeFrame()
{
	//Do graphics stuff here
	p.Draw(gfx);
}