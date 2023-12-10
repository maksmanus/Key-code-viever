#include <windows.h>
#include <stdio.h>

#ifndef WININTERFACES_H

    #define IDI_ICON1 "iw.ico"

    HINSTANCE MainInstance;
    HWND MainWindow;
    WNDCLASSA WindowClass;

    HWND TextField;

    HFONT font;

    HANDLE icon;

    char output[50];

    void setFont();

    void setbackgr();
    
#endif