#include <iostream>
using namespace std;
    
void task1 () {
    string s;
    getline(cin, s);
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    cout << s << endl;
}

int main() {
    task1();
    return 0;
}
