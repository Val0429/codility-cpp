// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> theParts;
    int max = std::numeric_limits<int>::min();
    /// created and cleaned by negative => positive
    for (auto it = A.begin(); it != A.end(); it++) {
        int num = *it;
        size_t size = theParts.size();
        /// no elements
        if (size == 0) {
            theParts.emplace_back(num);

        } else {
            int last = theParts[size-1];
            if (last > 0) {
                if (num > 0) {
                    /// positive => positive
                    int sum = theParts[size-1] + num;
                    if (sum < num) return -1;
                    theParts[size-1] = sum;
                } else {
                    /// positive => negative
                    theParts.emplace_back(num);
                }

            } else {
                if (num <= 0) {
                    /// negative => negative
                    int sum = theParts[size-1] + num;
                    if (sum > num) return -1;
                    theParts[size-1] = sum;
                    /// handle the all negative edge case
                    max = std::max(max, num);
                } else {
                    /// negative => positive
                    if (size > 1) {
                        int determine = theParts[size-1] + theParts[size-2];
                        theParts.pop_back();
                        theParts.pop_back();
                        if (determine > 0) {
                            theParts.emplace_back(determine + num);
                        } else {
                            theParts.emplace_back(num);
                        }
                    } else {
                        /// pure negative case
                        theParts.pop_back();
                        theParts.emplace_back(num);
                    }
                }
            }
        }
        max = std::max(max, theParts[0]);
    }
    return max;
}
