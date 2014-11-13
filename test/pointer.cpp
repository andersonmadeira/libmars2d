#include <MarsGE/Pointer.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace MarsGE;

class Person {
    public:
        Person(string name) {
            this->name = name;
            cout << "Person('" << name << "');" << endl;
        }
        ~Person() {
            cout << "~Person('" << name << "');" << endl; 
        }
        static void display(marsge::Pointer<Person> p) {
            cout << p->name << endl;
        }
    private:
        string name;
};

int main(int argc, char** argv) {
    Pointer<Person> x(new Person("Bob"));
    {
        Pointer<Person> y = x,
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
