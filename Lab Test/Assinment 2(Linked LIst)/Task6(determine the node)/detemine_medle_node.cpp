// Problem:  Given the head of a singly linked list, return the middle node of the linked list. If there 
// are two middle nodes, return the second middle node. 
//  Example: Input: 1 2 3 4 5  
//                             Output: 3 
//                             Input: 1 2 3 4 5 6  
//                             Output: 4  

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;

void insertAtEnd(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
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

struct node* findMiddle(struct node* head) {
    if (head == NULL) return NULL;

    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    struct node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "The middle node is: " << middle->info << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
