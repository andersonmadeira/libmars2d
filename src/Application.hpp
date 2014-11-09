#ifndef __MARS2D_APPLICATION_HPP__
#define __MARS2D_APPLICATION_HPP__

#include <SDL2/SDL.h>
#include "Exception.hpp"
#include "Pointer.hpp"
#include "Window.hpp"

namespace mars2d {
    class Application {
    public:
        // static stuff
        enum Flags {
            VIDEO = SDL_INIT_VIDEO,
            AUDIO = SDL_INIT_AUDIO,
            ALL = SDL_INIT_EVERYTHING
        };
        Application(Flags flags) throw(Exception); // may throw exception
        ~Application();
        static Pointer<Window> createWindow(const std::string& title, Uint16 width, Uint16 height) throw(Exception) {
            return new Window(title, width, height); 
        };
    };
}

#endif