#include <bits/stdc++.h>
using namespace std;
 
stack<int> sortStack(stack<int> &input) {
    stack<int> output;
 
    while (!input.empty()) {

        int tmp = input.top();
        input.pop();
        while (!output.empty() && output.top() > tmp) {
            input.push(output.top());
            output.pop();
        }

        output.push(tmp);
    }
 
    return output;
}