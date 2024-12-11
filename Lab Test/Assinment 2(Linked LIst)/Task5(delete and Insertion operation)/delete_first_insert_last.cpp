// Problem :  Delete a node from the beginning of a given linked list, and add that deleted node at 
// the end of that linked list 
//  Example: Input:    1 2 3 4 5 6 7 
//                   Output : 2 3 4 5 6 7 1

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void insertAtEnd(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteFromBeginningAndAddToEnd() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    struct node* temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }

    if (tail == NULL) {
        head = tail = temp;
        tail->next = NULL;
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
}

void display() {
    cout << "Your Linked List:" << endl;
    struct node* cur = head;
    while (cur != NULL) {
        cout << cur->info << " -> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int k;
    cout << "Enter the number of nodes: ";
    cin >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cout << "Enter the element number " << i + 1 << ": ";
        cin >> x;
        insertAtEnd(x);
    }
    display();

    deleteFromBeginningAndAddToEnd();
    display();

    return 0;
}
