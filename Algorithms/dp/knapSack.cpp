#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> weight, vector<int> value, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (weight[n - 1] > W) {
        return knapSack(W, weight, value, n - 1);
    } else {
        return max (
            value[n - 1] + knapSack(W - weight[n - 1], weight, value, n - 1),
            knapSack(W, weight, value, n - 1)
        );
    }
}

int knapSack_DP(int W, vector<int> weight, vector<int> value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i - 1] <= j) {
                dp[i][j] = max(
                    value[i - 1] + dp[i - 1][j - weight[i - 1]],
                    dp[i - 1][j]
                );
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}