// you can use includes, for example:
// #include <algorithm>
#include <stdexcept>
#include <math.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int max = 0;
    int current = 0;
    bool counting = false;

    while (N != 0) {
        bool match1 = (N & 1) == 1;
        if (counting == false) {
            if (match1) counting = true;
        } else {
            if (match1 == 0) current++;
            else {
                max = std::max(max, current);
                current = 0;
            }
        }
        N = N >> 1;
    }

    return max;
}
