// Friend Funcions in classes 

#include <iostream>
using namespace std;

class A {
    int x;
    friend void print(A &obj);

public: 
    A (int y) {
        x = y;
    }


};

void print(A &obj) {
    cout << obj.x << endl;
}


int main()
{
    A obj1(6);
    print(obj1);
    
}