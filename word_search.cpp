#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Static helper function to perform DFS search
    static bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        // If we have found the entire word, return true
        if (index == word.size()) return true;

        int n = mat.size(), m = mat[0].size();

        // Boundary conditions: 
        // 1. If (i, j) is out of bounds
        // 2. If the current cell does not match the required character
        // 3. If the cell is already visited
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[index] || visited[i][j]) 
            return false;

        // Mark the current cell as visited
        visited[i][j] = true;

        // Try all 4 possible directions
        bool found = dfs(mat, word, i + 1, j, index + 1, visited) || // Down
                     dfs(mat, word, i - 1, j, index + 1, visited) || // Up
                     dfs(mat, word, i, j + 1, index + 1, visited) || // Right
                     dfs(mat, word, i, j - 1, index + 1, visited);   // Left

        // Backtrack: Unmark the cell before returning
        visited[i][j] = false;

        return found;
    }

    // Static main function to check if the word exists in the matrix
    static bool isWordExist(vector<vector<char>>& mat, string word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Keeps track of visited cells

        // Iterate through every cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first letter matches, start DFS
                if (mat[i][j] == word[0]) {
                    if (dfs(mat, word, i, j, 0, visited)) 
                        return true;
                }
            }
        }

        return false; // Word not found
    }
};

// Driver Code
int main() {
    vector<vector<char>> mat1 = {{'T', 'E', 'E'}, 
                                 {'S', 'G', 'K'}, 
                                 {'T', 'E', 'L'}};
    string word1 = "GEEK";
    cout << (Solution::isWordExist(mat1, word1) ? "true" : "false") << endl; // Expected Output: true

    vector<vector<char>> mat2 = {{'T', 'E', 'U'}, 
                                 {'S', 'G', 'K'}, 
                                 {'T', 'E', 'L'}};
    string word2 = "GEEK";
    cout << (Solution::isWordExist(mat2, word2) ? "true" : "false") << endl; // Expected Output: false

    vector<vector<char>> mat3 = {{'A', 'B', 'A'}, 
                                 {'B', 'A', 'B'}};
    string word3 = "AB";
    cout << (Solution::isWordExist(mat3, word3) ? "true" : "false") << endl; // Expected Output: true

    return 0;
}
