#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(vector<int>& board, int row, int col, int n) {
        for (int prevCol = 0; prevCol < col; prevCol++) {
            int prevRow = board[prevCol];
            // Check if another queen is in the same row or on the same diagonal
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }
    
    // Recursive function to place queens in columns one by one
    void solveNQueens(vector<int>& board, int col, int n) {
        if (col == n) {
            result.push_back(board); // A valid configuration is found
            return;
        }
        
        // Try placing the queen in each row of the current column
        for (int row = 1; row <= n; row++) {
            if (isSafe(board, row, col, n)) {
                board[col] = row; // Place the queen
                solveNQueens(board, col + 1, n); // Recur for the next column
            }
        }
    }
    
    // Main function to solve the N-Queens problem
    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, 0); // Initialize the board
        solveNQueens(board, 0, n); // Start placing queens from the first column
        return result;
    }
    
    // Function to print solutions in board format
    void printSolutions(int n) {
        vector<vector<int>> solutions = nQueen(n);
        for (auto& sol : solutions) {
            cout << "Solution: ";
            for (int pos : sol) {
                cout << pos << " ";
            }
            cout << "\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (sol[j] == i + 1) cout << "Q ";
                    else cout << ". ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    sol.printSolutions(n);
    return 0;
}