#include <iostream>
using namespace std;

class solution {
private:
    int *arr;
    int size;
public:
    solution(int size) {
        this->size = size;
        arr = new int[size];
    }

    void set_arr(int *arr) {
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
    }

    void print_arr() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void selection_sort() {
        int min_index;
        for (int i = 0; i < size; i++) {
            min_index = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            swap(arr[i], arr[min_index]);
        }
    }

    void insertion_sort() {
        int temp;
        for (int i = 0; i < size; i++) {
            temp = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    void bubble_sort() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    int getPivot(int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    void quick_sort(int left, int right) {
        if (left < right) {
            int pivot = getPivot(left, right);
            quick_sort(left, pivot - 1);
            quick_sort(pivot + 1, right);
        }
    }

    void heapify(int *arr, int n, int root) {
        int largest = root;
        int l = 2 * root + 1;
        int r = 2 * root + 2;
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != root) {
            swap(arr[root], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heap_sort() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

};

int main() {
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    solution s(size);
    s.set_arr(arr);
    s.print_arr();
    s.quick_sort(0, size - 1);
    s.print_arr();
    return 0;
}