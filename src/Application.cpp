#include "Application.hpp"

namespace mars2d {
    Application::Application(Flags flags) throw(Exception) {
        Exception ex;
        if (SDL_Init(flags) < 0) {
            throw ex;
        }
    }
    Application::~Application() {
        SDL_Quit();
    }
}