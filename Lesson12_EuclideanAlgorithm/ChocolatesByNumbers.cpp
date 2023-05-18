// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    auto slices = std::vector<bool>(N);
    std::fill(slices.begin(), slices.end(), true);

    int pos = 0;
    int total = 0;
    /// O(N)
    while (true) {
        bool slice = slices[pos];
        if (slice == false) break;
        slices[pos] = false;
        total++;
        pos += M;
        pos %= N;
    }
    return total;
}
