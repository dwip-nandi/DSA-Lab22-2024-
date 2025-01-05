#include <bits/stdc++.h>
using namespace std;
struct Node {
    string name;
    double price;
    int quantity;
    Node* next;
};
Node* createNode(string name, double price, int quantity) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->price = price;
    newNode->quantity = quantity;
    newNode->next = nullptr;
    return newNode;
}

void addItem(Node*& head, string name, double price, int quantity) {
    Node* newNode = createNode(name, price, quantity);
    newNode->next = head;
    head = newNode;
}

void removeItem(Node*& head, string name) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item not found in the cart." << endl;
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Item removed from the cart." << endl;
}

// display the cart
void displayCart(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Product: " << temp->name << ", Price: " << temp->price << ", Quantity: " << temp->quantity << endl;
        temp = temp->next;
    }
}
// total cost of the cart
double calculateTotal(Node* head) {
    double total = 0.0;
    Node* temp = head;
    while (temp != nullptr) {
        total += temp->price * temp->quantity;
        temp = temp->next;
    }
    return total;
}

int main() {
    Node* cart = nullptr;  
    addItem(cart, "Oil", 500, 5);
    addItem(cart, "Sugar", 200, 25);
    addItem(cart, "Nuts", 300, 2);
    cout << "Shopping Cart:" << endl;
    displayCart(cart);
    double total = calculateTotal(cart);
    cout << "Total Cost: " << total <<"Taka"<< endl;
    // Remove an item from the cart
    removeItem(cart, "Oil");
    // Display the cart again
    cout << "Shopping Cart after removing :" << endl;
    displayCart(cart);
    // Calculate and display the total cost again
    total = calculateTotal(cart);
    cout << "Total Cost after removing : " << total <<"Taka"<< endl;
    return 0;
}
