#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	platform(Vec2(200.0f, 200.0f), 60, 60, Color(255,120,100)),
	p(Vec2(100.0f, 50.0f), 100.0f, 30, 30, Color(120,120,120))
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
	float dt = ft.Mark();
	p.Update(wnd.kbd, dt);
	p.DoCollision(platform);
}

void Game::ComposeFrame()
{
	//Do graphics stuff here
	platform.Draw(gfx);
	p.Draw(gfx);
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
