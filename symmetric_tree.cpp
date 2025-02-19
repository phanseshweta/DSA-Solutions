#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;  // Both nodes are NULL
    if (!t1 || !t2) return false; // One is NULL, other is not
    return (t1->val == t2->val)   // Check values
        && isMirror(t1->left, t2->right)  // Compare left subtree with right subtree
        && isMirror(t1->right, t2->left); // Compare right subtree with left subtree
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true; // An empty tree is symmetric
    return isMirror(root->left, root->right);
}

// Example Usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "True" : "False") << endl;
    return 0;
}
