#include <Windows.h>

int CALLBACK WinMain(
    HINSTANCE hInst,
    HINSTANCE hPrevInst,
    LPSTR     lpCmdLine,
    int       nShowCmd
)
{
    const auto pClassName = "SkyEngine";
    WNDCLASSEX wc = {0};
    wc.cbClsExtra = 0;
    wc.cbSize = sizeof(wc);
    wc.cbWndExtra = 0;
    wc.hbrBackground = nullptr;
    wc.hCursor = nullptr;
    wc.hIcon = nullptr;
    wc.hIconSm = nullptr;
    wc.hInstance = hInst;
    wc.lpfnWndProc = DefWindowProc;
    wc.lpszClassName = pClassName;
    wc.style = CS_OWNDC;
    wc.lpszMenuName = nullptr;

    RegisterClassEx(&wc);

    HWND hwnd = CreateWindowEx(0, 
        pClassName,
        "SkyEngine v0001",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        200, 200,
        800, 600,
        nullptr,
        nullptr,
        hInst,
        nullptr);

    ShowWindow(hwnd, SW_SHOW);
    while (true);
    return 0;
}