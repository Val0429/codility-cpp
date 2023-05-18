// you can use includes, for example:
#include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end(), [](const int a, const int b) {
        return abs(b) > abs(a);
    });
    // for (auto it = A.begin(); it != A.end(); it++) {
    //     cout << "it! " << *it << endl;
    // }

    int size = (int)A.size();
    int min = std::numeric_limits<int>::max();
    for (int i=0; i<size; i++) {
        int absa = abs(A[i]);
        for (int j=i; j<size; j++) {
            int absb = abs(A[j]);
            if (abs(absa + (-absb)) >= min) {
                // cout << "break with: " << (absa + absb) << endl;
                break;
            }
            // cout << "sum: " << abs(A[i] + A[j]) << endl;
            min = std::min(min, abs(A[i] + A[j]));
        }
    }
    return min;
}
