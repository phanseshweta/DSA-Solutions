#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to construct the tree recursively
Node* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, 
                      unordered_map<int, int> &inorderMap, int &preIndex, 
                      int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    // Pick current node from preorder traversal
    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    // Find index of this node in inorder traversal
    int inIndex = inorderMap[rootVal];

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, inorderMap, preIndex, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, inorderMap, preIndex, inIndex + 1, inEnd);

    return root;
}

// Main function to construct the binary tree
Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
    unordered_map<int, int> inorderMap;
    int n = inorder.size();

    // Store inorder element indices for quick lookup
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    int preIndex = 0; // Preorder index tracker
    return buildTreeHelper(preorder, inorder, inorderMap, preIndex, 0, n - 1);
}

// Function to print postorder traversal
void postorderTraversal(Node* root, vector<int> &postorder) {
    if (!root) return;
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->data);
}

// Driver function
int main() {
    vector<int> inorder = {2, 5, 4, 1, 3};
    vector<int> preorder = {1, 4, 5, 2, 3};

    Node* root = buildTree(inorder, preorder);

    vector<int> postorder;
    postorderTraversal(root, postorder);

    for (int val : postorder) {
        cout << val << " ";
    }

    return 0;
}
