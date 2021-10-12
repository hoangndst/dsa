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

    void quick_sort() {
        for (int i = 0; i < size; i++) {
            int pivot = arr[i];
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
    s.bubble_sort();
    s.print_arr();
    return 0;
}