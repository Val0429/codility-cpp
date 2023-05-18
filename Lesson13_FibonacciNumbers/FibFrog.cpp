// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::vector<int> getFibonaci(int max) {
    auto fibs = std::vector<int>();
    if (max < 1) return fibs;
    fibs.emplace_back(1);
    fibs.emplace_back(1);
    int f = 1;
    while (true) {
        int sum = fibs[f] + fibs[f-1];
        if (sum > max) break;
        fibs.emplace_back(sum);
        f++;
    }
    fibs.erase(fibs.begin());
    std::reverse(fibs.begin(), fibs.end());
    return fibs;
}

class FrogJump {
public:
    int position;
    int counter;
public:
    FrogJump(int position, int counter) : position(position), counter(counter) {}
};

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    std::vector<bool> accessed(size, false);
    std::vector<int> fibs = getFibonaci(size+1);

    auto jumps = std::vector<FrogJump>();
    jumps.emplace_back(FrogJump(-1, 0));
    int step = 0;

    while (true) {
        /// no other possible jumps
        if (step == (int)jumps.size()) return -1;

        auto thisJump = jumps[step];
        step++;
        for (auto it = fibs.begin(); it != fibs.end(); it++) {
            int fib = *it;
            int nextPos = thisJump.position + fib;
            /// jump to the other bank!
            if (nextPos == size) return thisJump.counter+1;
            if (
                /// too far
                nextPos > size ||
                /// no leaf
                A[nextPos] == 0 ||
                /// already tried
                accessed[nextPos] == true
                ) {
                    /// try next smaller fib
                    continue;
                }
            /// a successful (and larger) jump!
            jumps.emplace_back(FrogJump(nextPos, thisJump.counter+1));
            accessed[nextPos] = true;
        }
    }
}
