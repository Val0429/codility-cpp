// you can use includes, for example:
// #include <algorithm>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::map<int, bool> mapping;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    size_t size = A.size();
    /// do the mapping
    for (size_t i=1; i<=size; ++i) {
        mapping[i] = true;
    }

    for (auto it = A.begin(); it != A.end(); it++) {
        int value = *it;
        if (mapping.find(value) != mapping.end()) {
            mapping.erase(value);
        } else {
            return 0;
        }
    }
    if (mapping.size() == 0) return 1;
    else return 0;
}
