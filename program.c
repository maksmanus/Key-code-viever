#include "winInterfaces.h"

LRESULT WINAPI WindowProcess(HWND hwnd, UINT _iuint, WPARAM wparam, LPARAM lparam)
{

    switch (_iuint)
    {
        case WM_KEYDOWN:
            setFont();
            output[0] = '\0';
            sprintf(output, "KEY CODE: %d", wparam);
            SetWindowText(TextField, output);
            break;
        
        case WM_CLOSE:
            PostQuitMessage(0);
            break;   
        default:
            return DefWindowProc(hwnd, _iuint, wparam, lparam);
            break;
        }
}

void InitializeWindow();

void main()
{
    InitializeWindow();
}

void InitializeWindow()
{
    icon = LoadIcon(MainInstance, MAKEINTRESOURCE(IDI_ICON1));

    SendMessage(MainWindow, WM_SETICON, ICON_BIG, (LPARAM)icon);
    SendMessage(MainWindow, WM_SETICON, ICON_SMALL, (LPARAM)icon);

    MainInstance = GetModuleHandle(NULL);
    WindowClass.hInstance = MainInstance;
    WindowClass.lpszClassName = "WinClsss";
    WindowClass.lpszMenuName = "MenuEnchancer";
    WindowClass.lpfnWndProc = WindowProcess;
    WindowClass.hIcon = icon;

    RegisterClass(&WindowClass);

    MainWindow = CreateWindow("WinClsss", "KEY CODE VIEVER", WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME, 0, 0, 700, 300, NULL, NULL, NULL, NULL);
    ShowWindow(MainWindow, SW_SHOWDEFAULT);

    TextField = CreateWindow("STATIC", "Down Keyboard!", WS_VISIBLE | WS_VISIBLE | WS_CHILD, 200, 50, 150, 100, MainWindow, NULL, NULL, NULL);

    setFont();

    UpdateWindow(TextField);
    
    UpdateWindow(MainWindow);

    MSG message;

    while(GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

void setFont()
{
    font = CreateFont(25, 0, 0, 0, FW_BLACK, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"));
    SendMessage(TextField, WM_SETFONT, (WPARAM) font, TRUE);
}