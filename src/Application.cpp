#include "Application.hpp"

namespace mars2d {
    Application::Application(Flags flags) throw(Exception) {
        cout << "Application();" << endl;
        if (SDL_Init(flags) < 0) {
            throw Exception();
        }
    }
    
    void Application::delay(Uint32 ms) throw() {
        SDL_Delay(ms);
    }
    
    Application::~Application() {
        cout << "~Application();" << endl;
        SDL_Quit();
    }
}