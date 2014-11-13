#ifndef __MARSGAMEENGINE_APPLICATION_HPP__
#define __MARSGAMEENGINE_APPLICATION_HPP__

#include <SDL2/SDL.h>
#include "Exception.hpp"
#include <string>
#include "Pointer.hpp"
#include "Window.hpp"

namespace MarsGE {
    class Application {
    public:
        // static stuff
        enum Flags {
            VIDEO = SDL_INIT_VIDEO,
            AUDIO = SDL_INIT_AUDIO,
            ALL = SDL_INIT_EVERYTHING
        };
        Application(Flags flags) throw(Exception); // may throw exception
        void delay(Uint32 ms) throw();
        ~Application();
        static Window* createWindow(const std::string& title, Uint16 width, Uint16 height) throw(Exception) {
            return new Window(title, width, height); 
        }
    };
}

#endif