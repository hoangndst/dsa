#include <iostream>
using namespace std;

int arr[1000];
bool check[1000];
int n;
int count;

int sumOf(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Try(int k) {   
    for (int i = k + 1; i < n; i++) {
        if (!check[i]) {
            arr[k] = i;
            check[i] = true;
            if (sumOf(arr, k + 1) == n) {
                print(arr, k + 1);
                count++;
            } else {
                Try(k + 1);
            }
            check[i] = false;
        }
    }
}

int main() {
    count = 0;
    cin >> n;
    Try(0);
    cout << count;
    return 0;
}