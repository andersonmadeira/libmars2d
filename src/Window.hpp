#ifndef __MARSGAMEENGINE_WINDOW_HPP__
#define __MARSGAMEENGINE_WINDOW_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <string>
#include <iostream>
using std::endl;
using std::cout;
#include "Exception.hpp"
#include "Pointer.hpp"
#include "Color.hpp"
#include "Math/Point.hpp"
#include "Math/Size.hpp"
#include "Math/Line.hpp"

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
        void hide() throw();
        void show() throw();
        /// Bring window to front, above other windows and grab focus.
        void raise() throw();
        void update() throw();
        /// clears the window with the background color
        void clear() throw();
        void setClearColor(const Color& c) throw();
        // drawing methods
        void draw(const Math::Point& p) throw();
        void draw(const Math::Line& l) throw();
        ~Window();
    private:
        Window(const std::string& title, Uint16 width, Uint16 height) throw(Exception);
        SDL_Window* win;
        std::string title;
        SDL_GLContext glContext;
        
    friend class Application;
    };
}

#endif