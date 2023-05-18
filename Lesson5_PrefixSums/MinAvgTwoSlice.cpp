// you can use includes, for example:
#include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    size_t pos = 0;
    float min = std::numeric_limits<float>::max();
    // write your code in C++14 (g++ 6.2.0)

    size_t size = A.size();
    for (size_t i=0; i<size-2; i++) {
        float avg2 = ((float)A[i] + A[i+1]) / 2;
        float avg3 = ((float)A[i] + A[i+1] + A[i+2]) / 3;
        float avg = std::min<float>(avg2, avg3);
        if (avg < min) {
            pos = i;
            min = avg;
        }
    }
    /// missing case
    float avg2 = ((float)A[size-2] + A[size-1])/2;
    if (avg2 < min) {
        pos = size-2;
        min = avg2;
    }

    return (int)pos;
}
