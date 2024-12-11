//  Problem: Given a linked list, swap every two adjacent nodes and return its head. You must 
// solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves 
// may be changed.) 
//  Example: Input: 1 2 3 4 
//                    Output: 2 1 4 3 
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

struct node* swapPairs(struct node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct node* newHead = head->next;
    struct node* prev = NULL;
    struct node* cur = head;

    while (cur != NULL && cur->next != NULL) {
        struct node* nextPair = cur->next->next;
        struct node* second = cur->next;

        second->next = cur;
        cur->next = nextPair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = cur;
        cur = nextPair;
    }

    return newHead;
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

    head = swapPairs(head);
    display();

    return 0;
}

