// you can use includes, for example:
// #include <algorithm>
#include <math.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> result(N);

    int max_num = 0;
    int least_num = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        int value = (*it) - 1;
        if (value == N) {
            least_num = max_num;

        } else {
            int old_val = result[value];
            if (old_val < least_num) old_val = result[value] = least_num;
            int new_val = ++result[value];
            max_num = max(max_num, new_val);
        }
    }
    
    for (auto it = result.begin(); it != result.end(); it++) {
        if (*it < least_num) {
            *it = least_num;
        }
    }
    return result;
}
