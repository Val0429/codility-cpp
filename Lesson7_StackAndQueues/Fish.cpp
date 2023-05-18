// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    auto theStack = std::stack<int>();

    int passed = 0;
    for (int i=0; i<(int)A.size(); i++) {
        int direction = B[i];
        int power = A[i];
        /// downstream case
        if (direction == 1) {
            theStack.push(power);
            continue;
        }

        /// upstream case
        auto size = theStack.size();
        if (size == 0) {
            passed++;
            continue;
        }

        /// meet a fish
        while (theStack.size() > 0) {
            int backPower = theStack.top();
            if (backPower > power) goto gonext;
            theStack.pop();
        }
        passed++;

gonext:;
    }
    passed += theStack.size();
    return passed;
}
