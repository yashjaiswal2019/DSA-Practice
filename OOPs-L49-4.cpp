#include <iostream>
using namespace std;

class parent {
    public: 
        int x;
    
    protected: 
        int y;
    
    private: 
        int z;

};

class child1 : public parent {
    // x will public 
    // y will be protected 
    // but z will not be accessible in child1
};

class child2 : private parent {
    // x will be private 
    // y will also be private 
    // z will not be accessible in child2
};

class child3 : protected parent {
    // x will be protected 
    // y will be protected 
    // z will still not be accessible in the child3
};

int main()
{
    
}