// Multi-level Inheritance 

#include <iostream>
using namespace std;

class parent{
public: 
    parent(){
        cout << "Parent class." << endl;
    }

};

class child : public parent {
public:
    child(){
        cout << "Child Class." << endl;
    }
};

class grandChild : public child {
public:
    grandChild(){
        cout << "Grand-Child Class." << endl;
    }
};

int main()
{
    grandChild x;

    return 0;
    
}