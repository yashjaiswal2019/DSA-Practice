#include <iostream>
using namespace std;

class fruit {
    public : 
        string name;
        string color;
        int qty;
};

int main()
{
    fruit apple;
    apple.color = "red";
    cout << apple.color << endl;

    // another way of defining a object of a class 
    fruit *mango = new fruit();
    mango->color = "yellow";

    cout << mango-> color << endl;

    return 0;
}