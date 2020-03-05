#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	p({0,32,0,32}),
	b({ 0,64,0,64 }, { 300.0f, 300.0f }),
	c({ 0,64,0,64 }, { 364.0f, 364.0f }),
	d({ 0,64,0,64 }, { 300.0f, 428.0f })
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
	
	p.DoCollision(b.GetRect());
	p.DoCollision(c.GetRect());
	p.DoCollision(d.GetRect());

}

void Game::ComposeFrame()
{
	//Do graphics stuff here

	b.Draw(gfx);
	c.Draw(gfx);
	d.Draw(gfx);
	p.Draw(gfx);

}