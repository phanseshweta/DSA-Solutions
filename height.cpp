#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the maximum depth of the binary tree
int maxDepth(TreeNode* root) {
    // Base case: If the node is null, return depth as 0
    if (!root) return 0;
    
    // Recursively find the depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // The depth of the current node is the maximum of the two depths plus 1
    return max(leftDepth, rightDepth) + 1;
}

// Helper function to create a simple binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    cout << "Maximum depth of the tree: " << maxDepth(root) << endl;
    return 0;
}
