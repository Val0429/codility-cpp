// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    return (B/K) - (A/K) + (A%K == 0 ? 1 : 0);
}
