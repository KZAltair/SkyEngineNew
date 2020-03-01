#include "GameWindow.h"
#include <assert.h>

GameWindow::GameWindow(HINSTANCE hInstance, wchar_t* pArgs)
    :
    hInst(hInstance),
    args(pArgs)
{
   
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_CLASSDC;
    wc.lpfnWndProc = _HandleMsgSetup;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hbrBackground = nullptr;
    wc.hCursor = nullptr;
    wc.hIcon = nullptr;
    wc.hIconSm = nullptr;
    wc.lpszClassName = pWinClassName;
    wc.lpszMenuName = nullptr;

    RegisterClassEx(&wc);

    hWnd = CreateWindowEx(0,
        pWinClassName,
        L"SkyEngine v0001",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        200, 200,
        800, 600,
        nullptr,
        nullptr,
        hInst,
        this);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
}

GameWindow::~GameWindow()
{
    // unregister window class
    UnregisterClass(pWinClassName, hInst);
}

bool GameWindow::ProcessMessage()
{
    MSG msg;
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (msg.message == WM_QUIT)
        {
            return false;
        }
    }
    return true;
}

void GameWindow::ShowMessageBox(const std::wstring& title, const std::wstring& message, UINT type) const
{
    MessageBox(hWnd, message.c_str(), title.c_str(), type);
}

LRESULT WINAPI GameWindow::_HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // use create parameter passed in from CreateWindow() to store window class pointer at WinAPI side
    if (msg == WM_NCCREATE)
    {
        // extract ptr to window class from creation data
        const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
        GameWindow* const pWnd = reinterpret_cast<GameWindow*>(pCreate->lpCreateParams);
        // sanity check
        assert(pWnd != nullptr);
        // set WinAPI-managed user data to store ptr to window class
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
        // set message proc to normal (non-setup) handler now that setup is finished
        SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GameWindow::_HandleMsgThunk));
        // forward message to window class handler
        return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
    }
    // if we get a message before the WM_NCCREATE message, handle with default handler
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT WINAPI GameWindow::_HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // retrieve ptr to window class
	GameWindow* const pWnd = reinterpret_cast<GameWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    // forward message to window class handler
    return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT GameWindow::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	    case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
