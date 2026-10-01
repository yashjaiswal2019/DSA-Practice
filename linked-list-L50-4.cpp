// inserting at an arbitrary position in the list 
// also changing the value at Kth position in the list
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

void insertAt(node* &head , int val , int pos) {

    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    node *temp = head;
    for (int i = 1 ; i < pos ; i++) {
        temp = temp->next;
    }

    // now temp is pointing at pos-1
    node *new_node = new node(val);
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

void updateAt(node* &head , int val , int pos) {
    node *temp = head;
    for (int i = 0 ; i < pos ; i++) temp = temp->next;

    // now temp isopointing at the given node 
    temp->val = val;
    return;
}


int main() 
{
    node *head = new node(2);
    insertAtHead(head , 1);
    insertAtTail(head , 3);
    display(head);

    // now we have to insert at the Kth position in the list
    insertAt(head , 100 , 3);
    display(head);
    updateAt(head, 0 , 1);
    display(head);

    return 0;

}