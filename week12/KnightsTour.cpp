#include <bits/stdc++.h>
using namespace std;

int N = 8;

int isSafe(int x, int y, vector<vector<int>> &board) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1;
}

void printOutput(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("|%3d", board[i][j]);
        }
        printf("|\n");
    }
}

bool solveKTUtil(int x, int y, int move, vector<vector<int>> &board, vector<int> xMove, vector<int> yMove) {
    int k;
    int nextX, nextY;
    if (move == N * N) {
        return 1;
    }

    for (int k = 0; k < N; k++) {
        nextX = x + xMove[k];
        nextY = y + yMove[k];
        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = move;
            if (solveKTUtil(nextX, nextY, move + 1, board, xMove, yMove)) {
                return 1;
            } else {
                board[nextX][nextY] = -1;
            }
        }
    }
    return 0;
}

void solveKT() {
    vector<vector<int>> board(N, vector<int>(N, -1));
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};
    board[0][0] = 0;
    if (solveKTUtil(0, 0, 1, board, xMove, yMove)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("|%3d", board[i][j]);
            }
            printf("|\n");
        }
    } else {
        cout << "Solution does not exist";
    }
}

int main() {
    solveKT();
    return 0;
}