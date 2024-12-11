// margeshort of a linked list
// time complexity ------ O(n log n)

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

struct node* merge(struct node* left, struct node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->info <= right->info) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct node* findMiddle(struct node* head) {
    if (head == NULL) return head;
    struct node* slow = head;
    struct node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node* mergeSort(struct node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct node* middle = findMiddle(head);
    struct node* nextOfMiddle = middle->next;
    middle->next = NULL;

    struct node* left = mergeSort(head);
    struct node* right = mergeSort(nextOfMiddle);

    return merge(left, right);
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

    head = mergeSort(head);
    display();

    return 0;
}


