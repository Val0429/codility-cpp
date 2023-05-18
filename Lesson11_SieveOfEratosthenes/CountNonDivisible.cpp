// you can use includes, for example:
// #include <algorithm>
#include <cmath>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    int size = (int)A.size();
    // write your code in C++14 (g++ 6.2.0)
    // O(N)
    auto map1 = std::map<int, int>();
    for (auto it = A.begin(); it != A.end(); it++) {
        int value  = *it;
        if (map1.find(value) == map1.end()) {
            map1[value] = 1;
        } else {
            map1[value]++;
        }
    }

    // O(N * sqrt(N))
    auto map2 = std::map<int, int>();
    for (auto it = map1.begin(); it != map1.end(); it++) {
        int value = it->first;
        int numDivisors = 0;
        int sqrtV = (int)sqrt(value);
        for (int i=1; i<=sqrtV; i++) {
            if (value % i != 0) continue;
            int anotherFactor = value / i;
            if (map1.find(i) != map1.end()) {
                numDivisors += map1[i];
            }
            if (anotherFactor != i && map1.find(anotherFactor) != map1.end()) {
                numDivisors += map1[anotherFactor];
            }
        }
        map2[value] = numDivisors;
    }

    //
    auto result = vector<int>();
    for (auto it = A.begin(); it != A.end(); it++) {
        result.emplace_back(size - map2[*it]);
    }
    return result;
}
