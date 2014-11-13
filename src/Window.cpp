#include "Window.hpp"

namespace MarsGE {
    Window::Window(const std::string& title, Uint16 width, Uint16 height) throw(Exception) {
        this->title = title;
        win = NULL;
        
        //Use OpenGL 2.1
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
        
        if ((win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)) == NULL) {
            throw Exception();
        }
        cout << "Window('" << title << "');" << endl;
    }
    
    std::string Window::getTitle() const throw() {
        return this->title;
    }
    
    Uint32 Window::getId() const throw() {
        return win ? SDL_GetWindowID(win) : -1;
    }
    
    Math::Point Window::getPosition() const throw() {
        int x=-1,y=-1;
        
        if (win) SDL_GetWindowPosition(win, &x, &y);
        
        return Math::Point(x, y);
    }
    
    void Window::setPosition(const Math::Point& pos) throw() {
        int x = pos.x, y = pos.y;
        if (win) SDL_SetWindowPosition(win, x, y);
    }
    
    void Window::setTitle(const std::string& title) throw() {
        if (win) {
            this->title = title;
            SDL_SetWindowTitle(win, title.c_str());
        }
    }
    
    Math::Size Window::getSize() const throw() {
        int w=0, h=0;
        if (win)
            SDL_GetWindowSize(win, &w, &h);
        return Math::Size(w, h);
    }
    
    void Window::setSize(const Math::Size& size) throw() {
        if (win) SDL_SetWindowSize(win, size.width, size.height);
    }
    
    void Window::setSize(Uint32 width, Uint32 height) throw() {
        if (win) SDL_SetWindowSize(win, width, height);
    }
    
    void Window::hide() throw() {
        if (win) SDL_HideWindow(win);
    }
    
    void Window::show() throw() {
        if (win) SDL_ShowWindow(win);
    }
    
    void Window::raise() throw() {
        if (win) SDL_RaiseWindow(win);
    }
    
    void Window::update() throw() {
        if (win)
            SDL_UpdateWindowSurface(win);
    }
    
    void Window::sdlFillColor(Uint8 red, Uint8 green, Uint8 blue) throw() {
        SDL_Surface* sur = SDL_GetWindowSurface(win);
        SDL_FillRect(sur, NULL, SDL_MapRGB(sur->format, red, green, blue));
    }
    
    Window::~Window() {
        cout << "~Window('" << this->getTitle() << "');" << endl;
        if (win) {
            SDL_DestroyWindow(win);
            cout << "-> Window destroyed!";
        }
    }

}