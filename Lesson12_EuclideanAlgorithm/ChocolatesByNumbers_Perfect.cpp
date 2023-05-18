// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/// O(log(N + M))
int gcd(int N, int M, int res = 1) {
    int remainN = N % 2;
    int remainM = M % 2;
    if (N == M) return N * res;
    if (remainN == 0 && remainM == 0) return gcd(N/2, M/2, res*2);
    else if (remainN == 0) return gcd(N/2, M, res);
    else if (remainM == 0) return gcd(N, M/2, res);
    else if (N > M) return gcd(N-M, M, res);
    else return gcd(M-N, N, res);
}

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    return N / gcd(N, M);
}
