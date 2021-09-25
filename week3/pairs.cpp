#include <bits/stdc++.h>
using namespace std;

// int pairs(int k, vector<int> arr) {
//     int count = 0;
//     sort(arr.begin(), arr.end());
//     for (int i = 0; i < arr.size(); i++) {
//         for (int j = i + 1; j < arr.size(); j++) {
//             if (arr[j] - arr[i] == k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int pairs(int k, vector<int> arr) {
    set<int> s (arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i] + k) != s.end()) {
            count++;
        }
    }
    return count;
}