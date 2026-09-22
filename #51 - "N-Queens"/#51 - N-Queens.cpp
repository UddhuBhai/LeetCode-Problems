class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;

    bool isSafe(int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtrack(int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n)) {
                board[row][col] = 'Q';

                backtrack(row + 1, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        backtrack(0, n);

        return result;
    }
};