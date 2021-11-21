#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W) {
        return knapSack(W, wt, val, n - 1);
    } else {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), 
                                knapSack(W, wt, val, n - 1));
    }
}


int knapSack_DP(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            } else {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    return K[n][W];
}

int main() {
    int n; cin >> n;
    int W; cin >> W;
    int wt[n];
    int val[n];
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
        cin >> val[i];
    }   
    cout << knapSack_DP(W, wt, val, n) << endl;
    return 0;
}