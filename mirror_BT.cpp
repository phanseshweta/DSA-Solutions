#include <iostream>
using namespace std;

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to mirror a binary tree
void mirror(Node* node) {
    if (node == nullptr) return; // Base case: If node is null, do nothing

    // Swap left and right child
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recursively mirror left and right subtrees
    mirror(node->left);
    mirror(node->right);
}

// Function to perform in-order traversal of the tree
void inOrder(Node* root) {
    if (root == nullptr) return;
    
    inOrder(root->left);  // Visit left subtree
    cout << root->data << " "; // Print node value
    inOrder(root->right); // Visit right subtree
}

// Driver function to test the mirror function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Display original in-order traversal
    cout << "In-order traversal before mirroring: ";
    inOrder(root);
    cout << endl;

    // Mirror the binary tree
    mirror(root);

    // Display mirrored in-order traversal
    cout << "In-order traversal after mirroring: ";
    inOrder(root);
    cout << endl;

    return 0;
}
