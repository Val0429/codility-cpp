// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int sqrtN = (int)sqrt(N);
    int numFactors = 0;

    for (int i=1; i<=sqrtN; i++) {
        if (N % i == 0) numFactors++;
    }
    numFactors *= 2;
    if (sqrtN * sqrtN == N) {
        numFactors -= 1;
    }
    return numFactors;
}