#include <bits/stdc++.h>
using namespace std;

string balancedSums(vector<int> arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int left = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum -= arr[i];
        if (left == sum) {
            return "YES";
        }
        left += arr[i];
    }
    return "NO";
}
