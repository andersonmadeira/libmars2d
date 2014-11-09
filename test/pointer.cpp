#include <Mars2D/Pointer.hpp>
#include <string>
#include <iostream>

using namespace std;

class Person {
    public:
        Person(string name) {
            this->name = name;
            cout << "Person('" << name << "');" << endl;
        }
        ~Person() {
            cout << "~Person('" << name << "');" << endl; 
        }
        static void display(mars2d::Pointer<Person> p) {
            cout << p->name << endl;
        }
    private:
        string name;
};

int main(int argc, char** argv) {
    mars2d::Pointer<Person> x(new Person("Bob"));
    {
        mars2d::Pointer<Person> y = x,
                                z = new Person("Pat"),
                                w = z,
                                u;
        u = x;
        u = u;
        cout << "Displaying objects:" << endl;
        Person::display(x);
        Person::display(y);
        Person::display(z);
        Person::display(w);
    }
    Person::display(new Person("Susan"));
    return 0;
}
