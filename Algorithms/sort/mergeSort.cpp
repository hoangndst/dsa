#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
    int sub1 = m - l + 1;
    int sub2 = r - m;
    vector<int> left(sub1);
    vector<int> right(sub2);
    for (int i = 0; i < sub1; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < sub2; j++) {
        right[j] = arr[m + 1 + j];
    }
    int index1 = 0;
    int index2 = 0;
    int index = l;
    while (index1 < sub1 && index2 < sub2) {
        if (left[index1] <= right[index2]) {
            arr[index] = left[index1];
            index1++;
        } else {
            arr[index] = right[index2];
            index2++;
        }
        index++;
    }
    while (index1 < sub1) {
        arr[index] = left[index1];
        index1++;
        index++;
    }
    while (index2 < sub2) {
        arr[index] = right[index2];
        index2++;
        index++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
