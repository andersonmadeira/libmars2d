#ifndef __MARS2D_WINDOW_HPP__
#define __MARS2D_WINDOW_HPP__

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
using std::endl;
using std::cout;
#include "Exception.hpp"
#include "Pointer.hpp"

namespace mars2d {
    class Window {
    public:
        void setTitle(const std::string& title) throw();
        std::string getTitle() const throw();
        void update() throw();
        ~Window();
    private:
        Window(const std::string& title, Uint16 width, Uint16 height) throw(Exception);
        SDL_Window* win;
        std::string title;
        
    friend class Application;
    };
}

#endif