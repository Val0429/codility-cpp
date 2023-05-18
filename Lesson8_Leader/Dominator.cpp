// you can use includes, for example:
// #include <algorithm>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto theMap = std::map<int, std::vector<int>>();
    auto maxKey = std::vector<int>();
    size_t maxCount = 0;
    for (int i=0; i<(int)A.size(); i++) {
        int key = A[i];
        if (theMap.find(key) == theMap.end()) {
            theMap[key] = std::vector<int>();
        }
        theMap[key].emplace_back(i);
        auto size = theMap[key].size();
        if (size < maxCount) continue;
        if (size == maxCount) {
            maxKey.emplace_back(key);
        } else if (size > maxCount) {
            maxKey.clear();
            maxKey.emplace_back(key);
            maxCount = size;
        }
    }
    if (maxKey.size() != 1) return -1;

    auto& theVec = theMap[maxKey[0]];
    if (theVec.size() > (float)A.size() / 2) return theMap[maxKey[0]][0];
    return -1;
}
