#include <iostream>
using namespace std;

int arr[100];
int n;

void print(int *arr) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        arr[k] = i;
        if (k == n - 1) {
            print(arr);
        } else {
            Try(k + 1);
        }
    }
}

int main() {
    cin >> n;
    Try(0);
    return 0;
}