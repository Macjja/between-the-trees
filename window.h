/* Declarations for the Window class.
 *
 * Any drawing operations should be used on the Window's "bitmap,"
 * which is drawn onto the window when the "update" function is called.
 * 
 * This allows for the program to have a set resolution that is
 * automatically fitted onto the screen, no matter what the actual
 * window size is.
*/

#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <allegro5/allegro5.h>

class Window
{
    public:
        Window(int width, int height, int win_width, int win_height, ALLEGRO_COLOR bg_color = al_map_rgb(0, 0, 0));
        ~Window();
        
        void set_title(const char* title);
        void set_flag(int flag, bool onoff);
        
        void set_fit_mode(int mode);
        int get_fit_mode();
        
        void set_bg_color(ALLEGRO_COLOR bg_color);
        ALLEGRO_COLOR get_bg_color();
        
        bool set_pixel(int x, int y, ALLEGRO_COLOR color);
        ALLEGRO_COLOR get_pixel(int x, int y);
        
        int get_width();
        int get_height();
        int get_win_width();
        int get_win_height();
        int get_pix_width();
        int get_pix_height();
        int get_bitmap_x();
        int get_bitmap_y();
        
        void resize(int width, int height);
        void resize_window(int width, int height);
        
        void clear();
        
        void toggle_fullscreen();
        bool is_fullscreen();
        void toggle_pointer();
        bool is_pointer_visible();
        
        void fit_screen();
        void update();
        
        ALLEGRO_DISPLAY* get_display();
        ALLEGRO_BITMAP* get_bitmap();
    
    private:
        ALLEGRO_DISPLAY* disp;
        ALLEGRO_BITMAP* bitmap;
        int width, height, winWidth, winHeight;
        int bmpx, bmpy;
        bool fullscreen;
        bool showPointer;
        int fit;
        float pixWidth, pixHeight;
        ALLEGRO_COLOR bgColor;
};

#endif
