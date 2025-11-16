// N Queen Problem
// Approach: Classic Backtracking
// We place queens row-by-row, and at each row we try all columns.
// A placement (r, c) is valid only if no previously placed queen shares:
//   - Same column
//   - Same diagonal (major or minor)
// We store all valid board configurations.

#include <bits/stdc++.h>
using namespace std;

// Check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, vector<int> &colUsed,
            vector<int> &diag1, vector<int> &diag2, int n)
{
    // colUsed[col] = 1 means column already has a queen
    if (colUsed[col]) return false;

    // diag1 = (row - col + n)
    if (diag1[row - col + n]) return false;

    // diag2 = (row + col)
    if (diag2[row + col]) return false;

    return true;
}

// Backtracking function to build solutions
void solve(int row, int n, vector<string> &board,
           vector<vector<string>> &solutions,
           vector<int> &colUsed, vector<int> &diag1, vector<int> &diag2)
{
    // If row == n, we placed all queens -> one solution found
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    // Try every column in this row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, colUsed, diag1, diag2, n)) {

            // Place queen
            board[row][col] = 'Q';
            colUsed[col] = 1;
            diag1[row - col + n] = 1;
            diag2[row + col] = 1;

            // Move to next row
            solve(row + 1, n, board, solutions, colUsed, diag1, diag2);

            // BACKTRACK (remove the queen)
            board[row][col] = '.';
            colUsed[col] = 0;
            diag1[row - col + n] = 0;
            diag2[row + col] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> solutions;

    // Board initialized with '.'
    vector<string> board(n, string(n, '.'));

    // Helper arrays to mark columns and diagonals
    vector<int> colUsed(n, 0);
    vector<int> diag1(2*n, 0);
    vector<int> diag2(2*n, 0);

    solve(0, n, board, solutions, colUsed, diag1, diag2);

    // Print all solutions
    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (auto &b : solutions) {
        for (auto &row : b) cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
