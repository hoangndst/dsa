#include <iostream>
using namespace std;

int arr[1000];
bool check[1000];
int n;

void print(int *arr) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void Try(int k) {   
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            arr[k] = i;
            check[i] = true;
            if (k == n - 1) {
                print(arr);
            } else {
                Try(k + 1);
            }
            check[i] = false;
        }
    }
}

int main() {

    cin >> n;
    Try(0);
    return 0;
}