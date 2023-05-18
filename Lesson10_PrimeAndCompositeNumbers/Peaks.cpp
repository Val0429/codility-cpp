// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();

    /// find the peaks
    std::vector<int> peaks;
    for (int i=1; i<size-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks.emplace_back(i);
        }
    }

    for (int numBlocks=size/2; numBlocks>=1; numBlocks--) {
        if (size % numBlocks == 0) {
            int blockSize = size / numBlocks;
            int ithOkBlock = 0;
            for (auto it=peaks.begin(); it!=peaks.end(); it++) {
                int peaksIndex = *it;
                if (peaksIndex / blockSize == ithOkBlock) {
                    ithOkBlock++;
                }
            }
            if (ithOkBlock == numBlocks) return numBlocks;
        }
    }
    return 0;
}
