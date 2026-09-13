// Diamond problem when Inheriting multiple classes that have a common ancestor

#include <iostream>
using namespace std;

class parent{
public: 
    parent(){
        cout << "Parent class." << endl;
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

class grandChild : public child1 , public child2 {
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