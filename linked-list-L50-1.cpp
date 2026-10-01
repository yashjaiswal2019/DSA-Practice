// Implementation of a Singly Linked List
#include <iostream>
using namespace std;

class node {
    public: 
    int val;
    node *next;

    node(int data) {
        val = data;
        next = NULL;
    }
};

int main()
{
    node *n = new node(-1);
    cout << (*n).val << endl << (*n).next << endl; 
    return 0;
}