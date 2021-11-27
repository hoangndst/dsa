#include <bits/stdc++.h>
using namespace std;

int N = 8;

bool isSafe(int x, int y, vector<vector<int>> &board) {
    
    // <-
    for (int i = 0; i < x; i++) {
        if (board[i][y] == 1) return false;
    }

    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    for (int i = x, j = y; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solveNQUtils(int x, vector<vector<int>> &board) {
    if (x >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(x, i, board)) {
            board[x][i] = 1;
            if (solveNQUtils(x + 1, board)) {
                return true;
            } else {
                board[x][i] = 0;
            }
        }
    }
    return false;
}

void solveNQ() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQUtils(0, board)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    solveNQ();
    return 0;
}