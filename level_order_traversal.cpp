#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // Return an empty vector if the tree is empty
        if (root == nullptr) return {};
        
        vector<vector<int>> result;  // This will store the result of level order traversal
        queue<Node*> q;  // Queue to process nodes level by level
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            vector<int> level;  // Vector to store nodes of the current level
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();  // Get the front node from the queue
                q.pop();
                
                level.push_back(curr->data);  // Add the current node's data to the level
                
                // If the current node has a left child, push it to the queue
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                
                // If the current node has a right child, push it to the queue
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            
            result.push_back(level);  // Add the current level to the result
        }
        
        return result;  // Return the final result containing all levels
    }
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    Solution solution;
    
    // Create a binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    // Perform level order traversal
    vector<vector<int>> result = solution.levelOrder(root);
    
    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
SS