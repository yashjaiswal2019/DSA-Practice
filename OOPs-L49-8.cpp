// Heirarchical Inheritance

#include <iostream>
using namespace std;

class parent {
public: 
    parent() {
        cout << "Parent Class." << endl;
    }
};

class child1 : public parent {
public: 
    child1() {
        cout << "Child-1 Class." << endl;
    }
};

class child2 : public parent {
public: 
    child2() {
        cout << "Child-2 Class." << endl;
    }
};

int main()
{
    child1 x;
    cout << endl;
    child2 y;

    return 0;
    
}