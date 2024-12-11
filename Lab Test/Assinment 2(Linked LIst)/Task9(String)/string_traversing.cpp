//  Create a program in your preferred programing language to display string using 
// linked list and perform the following operations: 
//  Take a string of character from user and split the string in character, and then 
//  Insert each character into linked list. 
//  Example: Input: ICE 
//                   Output: I -> C -> E 

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

    return 0;
}
