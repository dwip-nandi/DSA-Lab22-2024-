#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
};
Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->key == key) return true;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);
}
int main() {
    Node* root = nullptr;
    int N, key;
    cout << "Enter the number of data items: ";
    cin >> N;
    cout << "Enter the data items: ";
    for (int i = 0; i < N; i++) {
        int item;
        cin >> item;
        root = insert(root, item);
    }
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;
    
    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Enter the key to search: ";
    cin >> key;
    if (search(root, key))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
