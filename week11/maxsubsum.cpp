#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }

    return max(left_sum, right_sum, left_sum + right_sum);
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h) / 2;

    return max(maxSubArraySum(arr, l, m), 
               maxSubArraySum(arr, m + 1, h), 
               maxCrossingSum(arr, l, m, h));
}