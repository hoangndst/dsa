#include <iostream>
#include <vector>
using namespace std;
/**
 * Best case, worst case and average case complexity of selection sort is O(n^2)
 */
void selectionSort(vector<int> &arr) {
    int minIndex;
    for (int i = 0; i < arr.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {

    vector<int> arr = {5, 2, 4, 6, 1, 3};
    selectionSort(arr);
    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}