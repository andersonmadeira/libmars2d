#ifndef __MARSGAMEENGINE_EXCEPTION_HPP__
#define __MARSGAMEENGINE_EXCEPTION_HPP__

#include <SDL2/SDL.h>
#include <exception>

namespace MarsGE {
    class Exception : public std::exception {
    public:
        virtual const char* what() const throw() {
            return SDL_GetError();
        }
    };
}

#endif