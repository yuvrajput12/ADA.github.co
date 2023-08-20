#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    // Check if there is a queen in the upper right diagonal
    i = row, j = col;
    while (i >= 0 && j < N) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: If all queens are placed, return true
    if (row == N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        // Check if it is safe to place a queen in this position
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing the queen in this position doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If no positions are safe in this row, return false
    return false;
}

void printSolution(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void nQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueens(board, 0, N)) {
        cout << "No solution exists." << endl;
    } else {
        printSolution(board, N);
    }
}

int main() {
    // Test the code
    nQueens(4);

    return 0;
}