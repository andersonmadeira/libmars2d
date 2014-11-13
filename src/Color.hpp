#ifndef __MARSGAMEENGINE_COLOR_HPP__
#define __MARSGAMEENGINE_COLOR_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

namespace MarsGE {
    struct Color {
        Color(float R, float G, float B, float A) : red(R), green(G), blue(B), alpha(A) {};
        // public attributes, no need to be private
        float red, green, blue, alpha;
    };
}

#endif
