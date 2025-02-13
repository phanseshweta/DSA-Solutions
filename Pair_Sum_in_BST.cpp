#include <iostream>
#include <unordered_set>
using namespace std;

// Definition of a BST Node
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    bool findPair(Node* root, int target, unordered_set<int>& seen) {
        if (!root) return false;  // Base case: If node is NULL, return false.

        // Check if complement exists in set
        if (seen.find(target - root->data) != seen.end()) 
            return true;  // Pair found!

        // Insert current node value into the set
        seen.insert(root->data);

        // Recursively search in left and right subtrees
        return findPair(root->left, target, seen) || findPair(root->right, target, seen);
    }

    bool findTarget(Node* root, int target) {
        unordered_set<int> seen;  // HashSet to store visited values
        return findPair(root, target, seen);
    }
};

// Helper function to insert nodes into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Driver code to test the function
int main() {
    Node* root = NULL;
    
    // Construct BST [7, 3, 8, 2, 4, N, 9]
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 9);

    Solution sol;
    int target = 12;

    if (sol.findTarget(root, target))
        cout << "True\n"; // Expected output: True
    else
        cout << "False\n";

    return 0;
}
