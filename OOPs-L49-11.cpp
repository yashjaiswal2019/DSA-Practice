// Run-Time Polymorphism.

#include <iostream>
using namespace std;

class parent {

public: 
    virtual void print() {      // virtual enables the fn over-riding.
        cout << "Parent Class" << endl;
    }

    void show() {
        cout << "Parent Class" << endl;
    }
};

class child : public parent {

public: 
    void print() {
        cout << "Child Class" << endl;
    }

    void show() {
        cout << "Child Class" << endl;
    }
};

int main()
{
    parent *p;
    child c;
    
    p = &c;

    p-> print();
    p-> show();

    return 0;
}