// Insert and delete operation of a string using linked list

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    char info;
    struct node* next;
};

struct node* head = NULL;

void insertAtEnd(char data) {
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

void insertAtBeginning(char data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = head;
    head = newnode;
}

void deleteNode(char data) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // Deleting the head node
    if (head->info == data) {
        struct node* temp = head;
        head = head->next;
        free(temp);
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
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for (char c : str) {
        insertAtEnd(c);
    }

    display();

    char data;
    cout << "Enter the character to insert at the beginning: ";
    cin >> data;
    insertAtBeginning(data);
    display();

    cout << "Enter the character to delete: ";
    cin >> data;
    deleteNode(data);
    display();

    return 0;
}
