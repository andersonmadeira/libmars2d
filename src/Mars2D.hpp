#ifndef __MARS2D_HPP__
#define __MARS2D_HPP__

#include <SDL2/SDL.h>

namespace mars2d {
    class Application {
    public:
        static bool init();
    private:
        Application();
    };
}

#endif