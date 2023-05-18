// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::vector<int> getFibonaci(int rungs) {
    auto fibs = std::vector<int>(rungs+1, 0);
    fibs[0] = 1;
    fibs[1] = 1;
    if (rungs == 1) return fibs;
    for (int i=2; i<=rungs; i++) {
        int sum = (fibs[i-1] + fibs[i-2]) % (1 << 30);
        fibs[i] = sum;
    }
    return fibs;
}

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    auto results = std::vector<int>(size);
    auto fibs = getFibonaci(size);

    for (int i=0; i<size; i++) {
        results[i] = (fibs[A[i]]) % (1 << B[i]);
    }
    return results;
}
