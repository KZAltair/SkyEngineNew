#include "GameWindow.h"
#include "Game.h"

Game::Game(GameWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brick({50.0f, 50.0f}),
	ball(Vec2(100.0f, 100.0f), Vec2(300.0f, 300.0f)),
	screenRect(0.0f,(float)Graphics::ScreenWidth, 0.0f, (float)Graphics::ScreenHeight),
	paddle(Vec2(400.0f, 500.0f))
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
	ball.Update(dt);
	ball.DoCollision(screenRect);
	paddle.Update(wnd.mouse, dt);
	paddle.DoWallCollision(screenRect);
	paddle.DoBallCollision(ball);

}

void Game::ComposeFrame()
{
	//Do graphics stuff here
	brick.Draw(gfx, Color(120, 120, 120));
	ball.Draw(gfx);
	paddle.Draw(gfx);
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
