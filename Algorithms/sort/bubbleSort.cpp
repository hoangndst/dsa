#include <iostream>
#include <vector>
using namespace std;

// Time Complexity is always O(n^2)
void bubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// Improved version of bubble sort
/**
 * Best case: O(n) when the array is already sorted
 * Worst case: O(n^2) when the array is in reverse order
 * Average case: O(n^2)
 */

void bubbleSortImproved(vector<int> &arr) {
    bool swapped = false;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {

    vector<int> arr = {5, 4, 3, 2, 1};
    bubbleSort(arr);
    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}