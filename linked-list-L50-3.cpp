// inserting at the Kth element in the linked list
// also how we can print a list
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

void insertAtTail(node* &head , int val) {
    node *temp = head;
    while (temp->next != NULL) temp = temp->next;

    // now temp is pointing at the last element of the list
    node *new_node = new node(val);
    temp->next = new_node;
}

void insertAtHead(node* &head , int val) {
    node *new_node = new node(val);
    new_node->next = head;
    head = new_node;
}

void display(node* &head) {
    node *temp = head;
    while (temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

int main() 
{
    node *head = new node(2);
    display(head);

    // inserting before the head element or we say first node 
    insertAtHead(head , 1);
    display(head);

    // inderting at the tail of the list
    insertAtTail(head , 3);
    display(head);

    return 0;

}