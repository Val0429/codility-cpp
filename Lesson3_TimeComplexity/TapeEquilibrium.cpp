// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t size = A.size();
    if (size < 2) return 0;

    /// Calculate Total
    int total = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        total += *it;
    }

    int part_left = A[0];
    int part_right = total - part_left;
    int diff = abs(part_left - part_right);
    int min_diff = diff;

    for (auto it = A.begin()+1; it != A.end()-1; it++) {
        part_left += *it;
        part_right = total - part_left;
        diff = abs(part_left - part_right);
        min_diff = min(diff, min_diff);
    }

    return min_diff;
}
