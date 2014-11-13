#include "Application.hpp"

namespace MarsGE {
    Application::Application(Flags flags) throw(Exception) {
        cout << "Application();" << endl;
        
        if (SDL_Init(flags) < 0) {
            throw Exception();
        }
        
        //Use OpenGL 2.1
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    }
    
    void Application::delay(Uint32 ms) throw() {
        SDL_Delay(ms);
    }
    
    Application::~Application() {
        cout << "~Application();" << endl;
        SDL_Quit();
    }
}