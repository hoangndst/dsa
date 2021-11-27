#include <iostream>
using namespace std;

void selectionSort() {
        int size; cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        int min_index;
        for (int i = 1; i < size - 1; i++) {
            min_index = i;
            for (int j = i + 1; j < size - 1; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            swap(arr[i], arr[min_index]);
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
}

int main() {

    selectionSort();

    return 0;
}
