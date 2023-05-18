// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    auto theStack = std::stack<char>();
    for (auto it = S.begin(); it != S.end(); it++) {
        char chr = *it;
        if (chr == '(') {
            theStack.push(chr);
        } else {
            if (theStack.size() == 0) return 0;
            theStack.pop();
        }
    }
    if (theStack.size() != 0) return 0;
    return 1;
}
