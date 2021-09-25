#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min = INT_MAX;
    vector<int> ans;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] - arr[i] < min) {
            min = arr[i + 1] - arr[i];
            ans.clear();
            ans.push_back(arr[i]);
            ans.push_back(arr[i + 1]);
        } else if (arr[i + 1] - arr[i] == min) {
            ans.push_back(arr[i]);
            ans.push_back(arr[i + 1]);
        }
    }

    return ans;
}