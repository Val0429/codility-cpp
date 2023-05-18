// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    /// do the sort
    size_t size = A.size();
    int result = 1;
    std::sort(A.begin(), A.begin() + size);
    for (auto it = A.begin(); it != A.end(); it++) {
        int value = *it;
        if (value < 1) continue;
        if (value == result) result++;
        else if (value < result) continue;
        else return result;
    }
    return result;
}
