//delete and insert any position dynamicaly , 
//lile insert first,last,medle and delete first,
//last and middle

#include <iostream>
#include <cstdlib>

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

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    struct node* temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }
    struct node* cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }
    free(tail);
    tail = cur;
    tail->next = NULL;
}

void deleteFromMiddle(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(temp);
        return;
    }
    struct node* cur = head;
    struct node* prev = NULL;
    for (int i = 1; i < position && cur != NULL; i++) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    prev->next = cur->next;
    if (cur->next == NULL) {
        tail = prev;
    }
    free(cur);
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
    int choice, data, position;
    do {
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Middle\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Middle\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data to insert at middle: ";
                cin >> data;
                cout << "Enter position to insert: ";
                cin >> position;
                insertAtMiddle(data, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteFromMiddle(position);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
