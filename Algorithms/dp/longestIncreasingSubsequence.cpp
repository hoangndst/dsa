#include <bits/stdc++.h>
using namespace std;

int _lis(vector<int> arr, int n, int &ans) {
    if (n == 0) {
        return 0;
    } 
    int res = 0;
    int max_ending_here = 1;
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, ans);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here) {
            max_ending_here = res + 1;
        }
    }
    if (max_ending_here > ans) {
        ans = max_ending_here;
    }
    return max_ending_here;
}

// int lis(vector<int> arr, int n) {
//     int ans = 0;
//     _lis(arr, n, ans);
//     return ans;
// }
// dynamic programming
int lis(vector<int> arr, int n) {
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int max_ending_here = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] + 1 > max_ending_here) {
                max_ending_here = dp[j] + 1;
            }
        }
        dp[i] = max_ending_here;
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return *max_element(dp.begin(), dp.end());
}
int main() {
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout <<"Length of lis is "<< lis(arr, arr.size());
    return 0;
}