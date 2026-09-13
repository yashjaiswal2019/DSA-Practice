#include <iostream>
using namespace std;

class complex {

public: 
    int real = 0;
    int imaginary = 0;

    complex(int x , int y) {
        real = x;
        imaginary = y;
    }

    // now lets do the operator overloading 
    complex operator+ (complex &c) {
        complex ans(0 , 0);
        ans.real = real + c.real;
        ans.imaginary = imaginary + c.imaginary;
        return ans;
    }
};

int main()
{
    complex c1 (2 , 3);
    complex c2(1 , 2);

    complex c3(0 , 0);
    c3 = c1 + c2;

    cout << c3.real << " " << c3.imaginary << endl;
}