// you can use includes, for example:
// #include <algorithm>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto set = std::set<int>();
    for (auto it = A.begin(); it != A.end(); it++) {
        int value = *it;
        set.insert(value);
    }
    return set.size();
}
