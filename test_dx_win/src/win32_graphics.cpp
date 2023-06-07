#include <windows.h>

#include "win32_graphics.h"
WNDPROC Wndproc;

global global_state GlobalState;

LRESULT Win32WindowCallBack(
    HWND WindowHandle,
    UINT Message,
    WPARAM WParam,
    LPARAM LParam
)
{
    LRESULT Result = {};
    switch (Message)
    {
    case WM_DESTROY:
    case WM_CLOSE: 
    {
        GlobalState.IsRunning = false;
    }break;
    default:
        Result = DefWindowProcA(WindowHandle, Message, WParam, LParam);
    }
    return Result;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nShowCmd)
{
    GlobalState.IsRunning = true;

    WNDCLASSA WindowCLass{};
    WindowCLass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    WindowCLass.lpfnWndProc = Win32WindowCallBack;
    WindowCLass.hInstance = hInstance;
    WindowCLass.hCursor = LoadCursorA(NULL, (LPCSTR) IDC_ARROW);
    WindowCLass.lpszClassName = "Graphics learning";
    if (!RegisterClassA(&WindowCLass)) {
        InvalidCodePath;
    }
    GlobalState.WindowHandle =
    CreateWindowExA(
        0,
        WindowCLass.lpszClassName,
        "Graphics learning",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1280,
        720,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!GlobalState.WindowHandle) {
        InvalidCodePath;
    }

    while (GlobalState.IsRunning)
    {
        MSG Message = {};
        while (PeekMessageA(&Message, GlobalState.WindowHandle, 0, 0, PM_REMOVE)) 
        {
            switch (Message.message)
            {
                case WM_QUIT:
                {
                    GlobalState.IsRunning = false;
                } break;

                default: {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                } break;
            }
        };

    }
   
   return 0;
}