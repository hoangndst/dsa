#include <iostream>
using namespace std;

int GCD_1(int x, int y) {
    x = abs(x);
    y = abs(y);
    if (x == 0) {
        return y;
    }
    return GCD_1(y % x, x);
}

int GCD_2(int x, int y) {
    x = abs(x);
    y = abs(y);
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    while (x != y) {
        if (x > y) {
            x -= y;
        } else {
            y -= x;
        }
    }
    return x;
}   


int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "GCD_1: " << GCD_1(x, y) << endl;
    cout << "GCD_2: " << GCD_2(x, y) << endl;

    return 0;
}