// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int min = std::numeric_limits<int>::max();
    int maxProfit = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        int num = *it;
        if (num == min) continue;
        if (num < min) {
            min = num;
        } else {
            maxProfit = std::max(maxProfit, num - min);
        }
    }
    return maxProfit;
}
