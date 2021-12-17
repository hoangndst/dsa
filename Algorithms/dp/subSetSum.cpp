#include <bits/stdc++.h>
using namespace std;

// recursive solution
bool isSubSetSum(vector<int> &arr, int n, int sum) {
    if (sum == 0) {
        return true;
    } else if (n == 0 && sum != 0) {
        return false;
    } else if (arr[n - 1] > sum) {
        return isSubSetSum(arr, n - 1, sum);
    } else {
        return isSubSetSum(arr, n - 1, sum) || isSubSetSum(arr, n - 1, sum - arr[n - 1]);
    }
}

// dynamic programming solution
bool isSubSetSum_DP(vector<int> &arr, int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = false;
            } else if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        } 
    }
    return dp[n][sum];
}