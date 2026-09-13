#include <iostream>
using namespace std;

class temp {
    int x;

    public: 
    void set(int n) {
        x = n;
    }

    int get() {
        return x;
    }
};

int main() {
    temp obj1;
    cout << obj1.get() << endl;
    obj1.set(8);
    cout << obj1.get() << endl;
}