// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int front = 0;
    int end = (int)A.size()-1;
    unsigned int last = 0;
    int results = 0;

    while (front <= end) {
        unsigned int absf = (unsigned int)abs(A[front]);
        unsigned int abse = (unsigned int)abs(A[end]);
        if (abse >= absf) {
            end--;
        } else {
            front++;
        }
        unsigned int larger = std::max(absf, abse);
        if (results == 0 || last != larger) {
            last = larger;
            results++;
        }
    }
    return results;
}
