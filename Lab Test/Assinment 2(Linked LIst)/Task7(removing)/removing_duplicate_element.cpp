// Problem:  Given a singly linked list consisting of N nodes. The task is to remove duplicates 
// (nodes with duplicate values) from the given list (if exists) and show the current linked list. 
//  Example: Input: 1 2 3 4 5 3 
//                             Output: 1 2 3 4 5

#include <iostream>
#include <unordered_set>
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

void removeDuplicates() {
    if (head == NULL) return;

    unordered_set<int> seen;
    struct node* cur = head;
    struct node* prev = NULL;

    while (cur != NULL) {
        if (seen.find(cur->info) != seen.end()) {
            prev->next = cur->next;
            free(cur);
        } else {
            seen.insert(cur->info);
            prev = cur;
        }
        cur = prev->next;
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

    removeDuplicates();
    display();

    return 0;
}
