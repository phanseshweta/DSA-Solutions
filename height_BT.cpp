#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Helper function to calculate height and update diameter
    int height(Node* node, int& diameter) {
        if (!node) return 0; // Base case: height of NULL node is 0

        // Recursively calculate height of left and right subtrees
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // Update the diameter if the path through the current node is longer
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }

    // Function to compute the diameter of the tree
    int diameter(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

// Function to build a sample binary tree
Node* buildSampleTree() {
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(9);
    return root;
}

// Main function to test the diameter function
int main() {
    Node* root = buildSampleTree();
    Solution sol;
    cout << "Diameter of the tree: " << sol.diameter(root) << endl;
    return 0;
}
