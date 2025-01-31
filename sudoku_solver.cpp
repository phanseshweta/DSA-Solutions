#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to check if placing num at mat[row][col] is valid
    bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            // Check if num exists in the current row, column, or 3x3 subgrid
            if (mat[row][i] == num || mat[i][col] == num ||
                mat[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                return false;
        }
        return true;
    }
    
    // Function to solve the Sudoku using backtracking
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Find an empty cell (marked by 0)
                if (mat[row][col] == 0) {
                    // Try placing numbers 1-9
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num;
                            // Recursively solve the next empty cell
                            if (solve(mat)) return true;
                            // Backtrack if no solution found
                            mat[row][col] = 0;
                        }
                    }
                    return false; // No valid number found, trigger backtracking
                }
            }
        }
        return true; // All cells are filled correctly
    }
    
    // Function to initiate the Sudoku solving process
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};

// Function to print the solved Sudoku grid
void printGrid(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample Sudoku puzzle with empty cells represented as 0
    vector<vector<int>> mat = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    Solution solver;
    solver.solveSudoku(mat);
    
    cout << "Solved Sudoku Grid:" << endl;
    printGrid(mat);
    
    return 0;
}
