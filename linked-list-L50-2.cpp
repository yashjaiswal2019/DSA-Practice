// traversing a singly linked list
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
    node *n = new node(1);
    node *temp = n;  
    for (int i = 0 ; i < 5 ; i++) {
        node *curr = new node(i+ 2);
        temp->next = curr; 
        temp = curr;
    }
    
    // printing the list 
    node *ptr = n;
    while (ptr != NULL) {
        cout << ptr->val << "--";
        ptr = ptr->next;
    }
    cout << endl << "ended" << endl;
    return 0;
}