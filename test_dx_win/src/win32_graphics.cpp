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
    LARGE_INTEGER TimerFrequency = {};
    Assert(QueryPerformanceFrequency(&TimerFrequency));

    // make a window
    {


        WNDCLASSA WindowCLass{};
        WindowCLass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        WindowCLass.lpfnWndProc = Win32WindowCallBack;
        WindowCLass.hInstance = hInstance;
        WindowCLass.hCursor = LoadCursorA(NULL, (LPCSTR)IDC_ARROW);
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
        GlobalState.DeviceContext = GetDC(GlobalState.WindowHandle);
    }

    {
        RECT ClientRect = {};
        Assert(GetClientRect(GlobalState.WindowHandle, &ClientRect));

        GlobalState.FrameBufferWidth = ClientRect.right - ClientRect.left;
        GlobalState.FrameBufferHeight = ClientRect.bottom - ClientRect.top;
        GlobalState.FrameBufferPixels = (u32*)malloc(sizeof(u32) *
                                                    GlobalState.FrameBufferWidth
                                                    * GlobalState.FrameBufferHeight);
    }

    LARGE_INTEGER BeginTime = {};
    LARGE_INTEGER EndTime = {};
    Assert(QueryPerformanceCounter(&BeginTime));
    // main loop
    while (GlobalState.IsRunning)
    {
        Assert(QueryPerformanceCounter(&EndTime));

        f32 FrameTime = f32(EndTime.QuadPart - BeginTime.QuadPart) / f32(TimerFrequency.QuadPart);
        BeginTime = EndTime;


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

        f32 Speed = 200.f;
        GlobalState.CurrOffset += Speed * FrameTime;


        for (u32 Y = 0; Y < GlobalState.FrameBufferHeight; Y++) {
            for (u32 X = 0; X < GlobalState.FrameBufferWidth; X++) {
                u32 PixelId = Y * GlobalState.FrameBufferWidth + X;
                
                u8 Red = (u8)(X - GlobalState.CurrOffset);
                u8 Green = (u8)Y;
                u8 Blue = 0;
                u8 Alpha = 0;
                u32 PixelColor = ((u32)Alpha << 32) | ((u32)Red << 16) | ((u32)Green << 8) | (u32)Blue;

                GlobalState.FrameBufferPixels[PixelId] = PixelColor; 
            }
             
        }
        RECT ClientRect = {};
        Assert(GetClientRect(GlobalState.WindowHandle, &ClientRect));

        u32 ClientWidth = ClientRect.right - ClientRect.left;
        u32 CliendHeight = ClientRect.bottom - ClientRect.top;

        BITMAPINFO BitmapInfo = {};

        BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        BitmapInfo.bmiHeader.biWidth = GlobalState.FrameBufferWidth;
        BitmapInfo.bmiHeader.biHeight = GlobalState.FrameBufferHeight;
        BitmapInfo.bmiHeader.biPlanes = 1;
        BitmapInfo.bmiHeader.biBitCount = 32;
        BitmapInfo.bmiHeader.biCompression = BI_RGB;

        Assert(StretchDIBits(
                            GlobalState.DeviceContext,
                            0,
                            0,
                            ClientWidth,
                            CliendHeight,
                            0, 
                            0,
                            GlobalState.FrameBufferWidth,
                            GlobalState.FrameBufferHeight,
                            GlobalState.FrameBufferPixels,
                            &BitmapInfo,
                            DIB_RGB_COLORS,
                            SRCCOPY));
    }
   
   return 0;
}