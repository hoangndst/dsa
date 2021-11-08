#include <bits/stdc++.h>
using namespace std;

/* {3, 4, 5, 2} and  sum = 9
                    (4, 9)
                    {True}
                   /        \  
                (3, 6)       (3, 9)
                    
                /    \        /   \ 
            (2, 2)  (2, 6)   (2, 5)  (2, 9)
            {True}  
            /   \ 
        (1, -3) (1, 2)  
        {False}  {True} 
                /    \
            (0, 0)  (0, 2)
            {True} {False}  
*/

bool isSubsetSum(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;
    if (arr[n - 1] > sum) return isSubsetSum(arr, n - 1, sum);
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Dynamic Programming

/**
 *     0 1 2 3 4 5 6 7 8 9 10
 *     ----------------------
 * 0 | 1 0 0 0 0 0 0 0 0 0 0 
 * 2 | 1 0 1 0 0 0 0 0 0 0 0
 * 5 | 1 0 1 0 0 1 0 1 0 0 0
 * 6 | 1 0 1 0 0 1 1 0 1 0 0
 * 2 | 1 0 1 0 0 0 0 1 1 0 1
 * 1 | 1 1 1 1 0 0 0 0 1 0 0
 * 7 | 1 1 1 0 0 0 0 1 1 1 (1)
 * 
 * */

bool isSubsetsum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1] = {0};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) dp[i][j] = true;
            else if (i == 0) dp[i][j] = false;
            else if (arr[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
        }
    }
    return dp[n][sum];
}

int main() {
    int n; cin >> n;
    int sum; cin >> sum;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (isSubsetSum(arr, n, sum)) cout << "YES";
    else cout << "NO";

    return 0;
}