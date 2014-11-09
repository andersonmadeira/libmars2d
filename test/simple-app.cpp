#include <Mars2D/Mars2D.hpp>
#include <iostream>
using std::cout;
using std::endl;

using namespace mars2d;

int main(int argc, char** argv) {
    Pointer<Window> win1, win2;
    Pointer<Application> app;
    
    try {
        app = new Application(Application::VIDEO);
        win1 = Application::createWindow("My Red Window", 320, 240);
        win1->sdlFillColor(255, 0, 0);
        win1->update();
        win2 = Application::createWindow("My Green Window", 320, 240);
        win2->sdlFillColor(0, 255, 0);
        win2->update();
        app->delay(3000);
    } catch(Exception const& ex) {
        cout << ex.what() << endl;
    }
    
    return 0;
}
