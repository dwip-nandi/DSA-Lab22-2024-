//  Insert a new node at the beginning, end, or middle of the list 
//  Example: Given linked list: 1 2 3 4 5 6 7 
//           After insertion at the beginning: 8 1 2 3 4 5 6 7 
//           After inserting at the middle: 1 2 3 4 8 5 6 7  
//           After inserting at the end: 1 2 3 4 5 6 7 8 

#include <bits/stdc++.h>
using namespace std;
struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void insertAtBeginning(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = head;
    head = newnode;
    if (tail == NULL) {
        tail = newnode;
    }
}

void insertAtEnd(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    if (tail == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void insertAtMiddle(int data, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    if (position == 1) {
        newnode->next = head;
        head = newnode;
        if (tail == NULL) {
            tail = newnode;
        }
        return;
    }
    struct node* cur = head;
    for (int i = 1; i < position - 1 && cur != NULL; i++) {
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Position out of bounds" << endl;
        free(newnode);
        return;
    }
    newnode->next = cur->next;
    cur->next = newnode;
    if (newnode->next == NULL) {
        tail = newnode;
    }
}

void display() {
    cout << endl << "Your Linked List:" << endl;
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

    int data, position;
    cout << "Enter the value to insert at the beginning: ";
    cin >> data;
    insertAtBeginning(data);
    display();

    cout << "Enter the value to insert at the end: ";
    cin >> data;
    insertAtEnd(data);
    display();

    cout << "Enter the value to insert in the middle: ";
    cin >> data;
    cout << "Enter the position to insert: ";
    cin >> position;
    insertAtMiddle(data, position);
    display();

    return 0;
}
