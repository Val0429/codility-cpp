// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t size = A.size();
    int result = 0;
    auto dps = std::vector<int>(size);
    auto dpe = std::vector<int>(size);
    std::fill(dps.begin(), dps.end(), 0);
    std::fill(dpe.begin(), dpe.end(), 0);

    for (int i=0, t = (int)size-1; i<(int)size; i++) {
        int radius = A[i];
        int s = (i - radius) < 0 ? 0 : (i - radius);
        int e = 0;

        int plus = i + radius;
        /// overflow case
        if (plus < radius) e = t;
        else {
            e = plus > t ? t : plus;
        }
        dps[s]++;
        dpe[e]++;
    }

    for (int i=0, t=0; i<(int)size; i++) {
        int s = dps[i];
        if (s > 0) {
            result += s * t;
            result += s * (s-1) / 2;
            if (result > 10000000) return -1;
            t += s;
        }
        t -= dpe[i];
    }
    return result;
}
