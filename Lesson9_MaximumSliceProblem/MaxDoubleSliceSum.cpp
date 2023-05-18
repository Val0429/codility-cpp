// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t size = A.size();
    std::vector<int> maxLeft(size);
    std::fill(maxLeft.begin(), maxLeft.end(), 0);
    std::vector<int> maxRight(size);
    std::fill(maxRight.begin(), maxRight.end(), 0);
    /// find max left
    for (int i=1; i<(int)size-1; i++) {
        maxLeft[i] = std::max(0, maxLeft[i-1] + A[i]);
    }
    /// find max right
    for (int i=(int)size-2; i>0; i--) {
        maxRight[i] = std::max(0, maxRight[i+1] + A[i]);
    }
    /// find the max of both sum
    int max = 0;
    for (int i=0; i<(int)size-2; i++) {
        max = std::max(max, maxLeft[i] + maxRight[i+2]);
    }
    return max;
}
