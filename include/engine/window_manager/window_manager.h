#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <windows.h>
#include <string>
#include <iostream>

#include "engine/interfaces/irenderable.h"

struct WindowConfig
{
    std::wstring window_name{L"default_window"};
    std::wstring class_name{L"default_class"};
    int width{1280};
    int height{720};
    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
};

class WindowManager
{
public:
    WindowManager();
    ~WindowManager();

    bool create_window(WindowConfig config, IRenderable* renderer);
    bool process_messages();
    void update_window();

    HWND get_hwnd();

private:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT class_window_proc(UINT umsg, WPARAM wparam, LPARAM lparam);
    HINSTANCE hInstance;

    HWND hwnd{NULL};
    IRenderable* renderer;
};

#endif
