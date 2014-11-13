#ifndef __MARSGAMEENGINE_DIMENSION_HPP__
#define __MARSGAMEENGINE_DIMENSION_HPP__

#include <SDL2/SDL.h>

namespace MarsGE {
    namespace Math {
        struct Size {
            Uint32 width, height;
            Size(Uint32 w, Uint32 h) : width(w), height(h) {};
        };
    }
}

#endif