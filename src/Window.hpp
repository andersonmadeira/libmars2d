#ifndef __MARS2D_WINDOW_HPP__
#define __MARS2D_WINDOW_HPP__

#include <SDL2/SDL.h>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include "Exception.hpp"
#include "Pointer.hpp"

namespace mars2d {
    class Window {
    public:
        void setTitle(const string& title) throw();
        string getTitle() const throw();
        void update() throw();
        ~Window();
    private:
        Window(const string& title, Uint16 width, Uint16 height) throw(Exception);
        SDL_Window* win;
        string title;
        
    friend class Application;
    };
}

#endif