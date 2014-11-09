#include "Window.hpp"

namespace mars2d {
    Window::Window(const std::string& title, Uint16 width, Uint16 height) throw(Exception) {
        this->title = title;
        win = NULL;
        if ((win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)) == NULL) {
            throw Exception();
        }
        cout << "Window('" << title << "');" << endl;
    }
    
    std::string Window::getTitle() const throw() {
        return this->title;
    }
    
    void Window::setTitle(const std::string& title) throw() {
        if (win) {
            this->title = title;
            SDL_SetWindowTitle(win, title.c_str());
        }
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