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
    if (tail == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteNode(int data) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // Deleting the head node
    if (head->info == data) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        if (head == NULL) {
            tail = NULL;
        }
        return;
    }

    // Deleting a node in the middle or end
    struct node* cur = head;
    struct node* prev = NULL;
    while (cur != NULL && cur->info != data) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Node not found" << endl;
        return;
    }

    prev->next = cur->next;
    if (cur->next == NULL) {
        tail = prev;
    }
    free(cur);
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

    int data;
    cout << "Enter the value to delete: ";
    cin >> data;
    deleteNode(data);
    display();

    return 0;
}
