#include <iostream>
#include <vector>
using namespace std;
// recursive binary search
int binarySearch(vector<int> &arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

// iterative binary search

int binarySearch(vector<int> &arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 10;
    int result = binarySearch(arr, 0, arr.size() - 1, x);
    if (result == -1) {
        cout << "Element not found";
    } else {
        cout << "Element found at index " << result;
    }
    return 0;
}