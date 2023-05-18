// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    std::stack<int> theStack;

    int total = 0;
    for (auto it = H.begin(); it != H.end(); it++) {
        int height = *it;
        if (theStack.size() != 0) {
            while (theStack.size() != 0) {
                int lastHeight = theStack.top();
                if (lastHeight > height) {
                    theStack.pop();
                    continue;
                } else if (lastHeight == height) {
                    break;
                } else {
                    theStack.push(height);
                    total++;
                    break;
                }
            }
        }
        if (theStack.size() == 0) {
            theStack.push(height);
            total++;
        }
    }
    return total;
}
