#include <iostream>
using namespace std;

class rectangle {
    public:
    int l;
    int b;

    // default constructor
    rectangle (){
        l = 0;
        b = 0;  
    }

    // parametric constructor 
    rectangle (int length , int breath) {
        l = length; 
        b = breath; 
    }

    // copy constructor 
    rectangle (rectangle &x) {
        l = x.l;
        b = x.b;
    }

    ~rectangle(){
        cout << "Constructor has been called." << endl;
    }
};

int main() {
    rectangle r1;
    cout << r1.l << " - " << r1.b << endl;

    rectangle *r2 = new rectangle();
    r2->l = 2;
    r2->b = 3;
    cout << r2->l << " - " << r2->b << endl;
    delete r2;

    rectangle r3(r1);
    cout << r3.l << " - " << r3.b << endl;
    return 0;
}