#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	p(Vec2(100.0f, 50.0f), 200.0f, 30, 30, Color(120,120,120))
{
	Vec2 offset = { 100.0f, 400.0f };
	for (int i = 0; i < 4; ++i)
	{
		platforms.push_back(Platform(offset, 60, 60, Color(255, 120, 100)));
		offset.x += 150.0f;

	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		Update(dt);
		elapsedTime -= dt;
	}
	
	ComposeFrame();
	gfx.EndFrame();
}

void Game::Update(float dt)
{
	//Do update game stuff here
	p.Update(wnd.kbd, dt);
	for (Platform& plat : platforms)
	{
		plat.DoCollision(p);
	}
}

void Game::ComposeFrame()
{
	//Do graphics stuff here
	for (Platform& plat : platforms)
	{
		plat.Draw(gfx);
	}
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
