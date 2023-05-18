// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t size = A.size();

    /// find the peaks
    std::vector<int> peaks;
    for (int i=1; i<(int)size-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks.emplace_back(i);
        }
    }

    /// the maximum flags should be less than the sqrt of size
    size_t peakSize = peaks.size();
    int sqrtN = (int)sqrt(size);
    int capPeaks = std::min(sqrtN+1, (int)peakSize);
    int max = 0;
    for (int flagCount=capPeaks; (flagCount>0) & (flagCount>max); flagCount--) {
        int lastFlag = 0;
        int setFlags = 0;
        for (auto peak = peaks.begin(); peak != peaks.end(); peak++) {
            int pos = *peak;
            if (lastFlag == 0 || (pos - lastFlag) >= flagCount) {
                lastFlag = pos;
                setFlags++;
                if (setFlags == flagCount) {
                    max = std::max(max, setFlags);
                    break;
                }
            }
        }
    }
    return max;
}
