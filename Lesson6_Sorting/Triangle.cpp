// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t size = A.size();
    if (size < 3) return 0;

    std::sort(A.begin(), A.end());
    for (size_t i=0; i<size-2; i++) {
        if ((A[i+2] - A[i+1]) < A[i]) {
            return 1;
        }
    }
    return 0;
}
