// you can use includes, for example:
// #include <algorithm>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::map<int, bool> mapping;
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    /// do the mapping
    for (int i=1; i<=X; ++i) {
        mapping[i] = true;
    }

    /// iterate
    int time = 0;
    for (auto it = A.begin(); it != A.end(); it++, time++) {
        int value = *it;
        if (mapping.find(value) != mapping.end()) {
            mapping.erase(value);
            if (mapping.size() == 0) return time;
        }
    }
    return -1;
}
