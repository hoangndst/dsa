#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 5;
    int index = search(arr, x);
    if (index == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << index << endl;
    }

    return 0;
}