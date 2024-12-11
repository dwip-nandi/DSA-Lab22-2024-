//swaping diffrent positions

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

void swapNodes(int pos1, int pos2) {
    if (pos1 == pos2) return;

    struct node* prev1 = NULL, *curr1 = head;
    for (int i = 1; curr1 != NULL && i < pos1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    struct node* prev2 = NULL, *curr2 = head;
    for (int i = 1; curr2 != NULL && i < pos2; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr1 == NULL || curr2 == NULL) return;

    if (prev1 != NULL) {
        prev1->next = curr2;
    } else {
        head = curr2;
    }

    if (prev2 != NULL) {
        prev2->next = curr1;
    } else {
        head = curr1;
    }

    struct node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
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

    int pos1, pos2;
    cout << "Enter the positions of nodes to swap: ";
    cin >> pos1 >> pos2;
    swapNodes(pos1, pos2);
    display();

    return 0;
}
