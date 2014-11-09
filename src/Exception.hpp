#ifndef __MARS2D_EXCEPTION_HPP__
#define __MARS2D_EXCEPTION_HPP__

#include <SDL2/SDL.h>
#include <exception>

namespace mars2d {
    class Exception : public std::exception {
    public:
        virtual const char* what() const throw() {
            return SDL_GetError();
        }
    };
}

#endif