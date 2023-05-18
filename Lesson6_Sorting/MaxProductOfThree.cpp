// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end());
    size_t size = A.size();
    int product_a = A[0] * A[1] * A[size-1];
    int product_b = A[size-3] * A[size-2] * A[size-1];

    return std::max<int>(product_a, product_b);
}
