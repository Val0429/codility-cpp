// you can use includes, for example:
#include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    std::sort(A.begin(), A.end());
    int tail = 0;
    int head = size-1;
    int min = abs(A[tail] + A[head]);

    while (tail <= head) {
        int sum = A[tail] + A[head];
        min = std::min(min, abs(sum));
        if (sum <= 0) tail++;
        else head--;
    }

    return min;
}
