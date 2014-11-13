#ifndef __MARSGAMEENGINE_WINDOW_HPP__
#define __MARSGAMEENGINE_WINDOW_HPP__

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
using std::endl;
using std::cout;
#include "Exception.hpp"
#include "Pointer.hpp"
#include "Math/Point.hpp"
#include "Math/Size.hpp"

namespace MarsGE {
    class Window {
    public:
        void setTitle(const std::string& title) throw();
        std::string getTitle() const throw();
        Uint32 getId() const throw();
        Math::Point getPosition() const throw();
        void setPosition(const Math::Point& pos) throw();
        Math::Size getSize() const throw();
        void setSize(const Math::Size& size) throw();
        void setSize(Uint32 width, Uint32 height) throw();
        void update() throw();
        void sdlFillColor(Uint8 red, Uint8 green, Uint8 blue) throw();
        ~Window();
    private:
        Window(const std::string& title, Uint16 width, Uint16 height) throw(Exception);
        SDL_Window* win;
        std::string title;
        
    friend class Application;
    };
}

#endif