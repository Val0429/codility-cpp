// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int maxEnding = A[0];
    int maxSoFar = A[0];

    for (int i=1; i<(int)A.size(); i++) {
        maxEnding = std::max(A[i], maxEnding + A[i]);
        maxSoFar = std::max(maxSoFar, maxEnding);
    }
    return maxSoFar;
}
