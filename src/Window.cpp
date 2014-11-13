#include "Window.hpp"

namespace MarsGE {
    Window::Window(const std::string& title, Uint16 width, Uint16 height) throw(Exception) {
        this->title = title;
        win = NULL;
        
        if ((win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)) == NULL) {
            throw Exception();
        }
        cout << "Window('" << title << "');" << endl;
        
        // Create an OpenGL context associated with the window.
        glContext = SDL_GL_CreateContext(win);
        
        // vsync
        SDL_GL_SetSwapInterval(1);
        
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(win);
        
        //Initialize Projection Matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //Initialize Modelview Matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    
    std::string Window::getTitle() const throw() {
        return this->title;
    }
    
    Uint32 Window::getId() const throw() {
        return SDL_GetWindowID(win);
    }
    
    Math::Point Window::getPosition() const throw() {
        int x=-1,y=-1;
        
        SDL_GetWindowPosition(win, &x, &y);
        
        return Math::Point(x, y);
    }
    
    void Window::setPosition(const Math::Point& pos) throw() {
        int x = pos.x, y = pos.y;
        SDL_SetWindowPosition(win, x, y);
    }
    
    void Window::setTitle(const std::string& title) throw() {
        this->title = title;
        SDL_SetWindowTitle(win, title.c_str());
    }
    
    Math::Size Window::getSize() const throw() {
        int w=0, h=0;
        SDL_GetWindowSize(win, &w, &h);
        return Math::Size(w, h);
    }
    
    void Window::setSize(const Math::Size& size) throw() {
        SDL_SetWindowSize(win, size.width, size.height);
    }
    
    void Window::setSize(Uint32 width, Uint32 height) throw() {
        SDL_SetWindowSize(win, width, height);
    }
    
    void Window::hide() throw() {
        SDL_HideWindow(win);
    }
    
    void Window::show() throw() {
        SDL_ShowWindow(win);
    }
    
    void Window::raise() throw() {
        SDL_RaiseWindow(win);
    }
    
    void Window::update() throw() {
        SDL_GL_SwapWindow(win);
    }
    
    void Window::clear() throw() {
        SDL_GL_MakeCurrent(win, glContext);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void Window::setClearColor(const Color& c) throw() {
        SDL_GL_MakeCurrent(win, glContext);
        glClearColor(c.red, c.green, c.blue, c.alpha);
    }
    
    void Window::draw(const Math::Point& p) throw() {
        // pass
    }
    
    void Window::draw(const Math::Line& l) throw() {
        // pass
    }
    
    Window::~Window() {
        cout << "~Window('" << this->getTitle() << "');" << endl;
        if (win) {
            SDL_GL_DeleteContext(glContext);
            SDL_DestroyWindow(win);
            cout << "-> Window destroyed!";
        }
    }

}