/* Implementation of the Window class */

#include "window.h"

Window::Window(int width, int height, int win_width, int win_height, ALLEGRO_COLOR bg_color)
{
    Window::width = width;
    Window::height = height;
    winWidth = win_width;
    winHeight = win_height;
    bgColor = bg_color;
    bmpx = 0, bmpy = 0;
    fullscreen = false;
    showPointer = true;
    fit = 0;
    
    disp = al_create_display(win_width, win_height);
    bitmap = al_create_bitmap(width, height);
    
    fit_screen();
}
Window::~Window()
{
    al_destroy_bitmap(bitmap);
    al_destroy_display(disp);
}

void Window::set_title(const char* title)
{
    al_set_window_title(disp, title);
}
void Window::set_flag(int flag, bool val)
{
    al_set_display_flag(disp, flag, val);
}
void Window::set_fit_mode(int mode)
{
    fit = mode;
    if (fit > 2)
        fit = 0;
    fit_screen();
}
int Window::get_fit_mode()
{
    return fit;
}

void Window::set_bg_color(ALLEGRO_COLOR bg_color)
{
    bgColor = bg_color;
}
ALLEGRO_COLOR Window::get_bg_color()
{
    return bgColor;
}

bool Window::set_pixel(int x, int y, ALLEGRO_COLOR color)
{
    if (al_get_target_bitmap() == bitmap)
        al_put_blended_pixel(x, y, color);
    else
        return false;
    return true;
}   
ALLEGRO_COLOR Window::get_pixel(int x, int y)
{
    return al_get_pixel(bitmap, x, y);
}

int Window::get_width()
{
    return width;
}
int Window::get_height()
{
    return height;
}
int Window::get_win_width()
{
    return winWidth;
}
int Window::get_win_height()
{
    return winHeight;
}
int Window::get_pix_width()
{
    return pixWidth;
}
int Window::get_pix_height()
{
    return pixHeight;
}

void Window::resize(int width, int height)
{
    Window::width = width;
    Window::height = height;
}
void Window::resize_window(int width, int height)
{
    winWidth = width;
    winHeight = height;
    
    if (fullscreen)
    {
        al_set_display_flag(disp, ALLEGRO_FULLSCREEN_WINDOW, false);
        fullscreen = false;
    }
    al_resize_display(disp, winWidth, winHeight);
}

void Window::clear()
{
    if (al_get_target_bitmap() == bitmap)
        al_clear_to_color(bgColor);
}

void Window::toggle_fullscreen()
{
    fullscreen = !fullscreen;
    al_set_display_flag(disp, ALLEGRO_FULLSCREEN_WINDOW, fullscreen);
}
bool Window::is_fullscreen()
{
    return fullscreen;
}
void Window::toggle_pointer()
{
    showPointer = !showPointer;
    if (showPointer)
        al_show_mouse_cursor(disp);
    else
        al_hide_mouse_cursor(disp);
}
bool Window::is_pointer_visible()
{
    return showPointer;
}

void Window::update()
{
    if (al_get_target_bitmap() != al_get_backbuffer(disp))
        al_set_target_backbuffer(disp);
    
    al_clear_to_color(bgColor);
    al_draw_scaled_bitmap(bitmap, 0, 0, width, height, bmpx, bmpy, width * pixWidth, height * pixHeight, 0);
    al_flip_display();
}

ALLEGRO_DISPLAY* Window::get_display()
{
    return disp;
}
ALLEGRO_BITMAP* Window::get_bitmap()
{
    return bitmap;
}

void Window::fit_screen()
{
    winWidth = al_get_display_width(disp);
    winHeight = al_get_display_height(disp);
    pixWidth = (float)winWidth / width;
    pixHeight = (float)winHeight / height;
    
    if (fit == 0)
    {
        if (pixWidth < pixHeight)
            pixHeight = pixWidth;
        else
            pixWidth = pixHeight;
    }
    else if (fit == 1)
    {
        if (pixWidth > pixHeight)
            pixHeight = pixWidth;
        else
            pixWidth = pixHeight;
    }
    
    bmpx = (winWidth - width * pixWidth) / 2;
    bmpy = (winHeight - height * pixHeight) / 2;
}
