// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a%b);
}

bool internalPrimeDivisors(int ref, int a) {
    if (a == 1) return true;
    int gcd_result = gcd(ref, a);
    if (gcd_result == 1 && a > 1) return false;
    return internalPrimeDivisors(ref, a / gcd_result);
}

bool commonPrimeDivisors(int a, int b) {
    int ref = gcd(a, b);
    if (ref == 1 && (a != 1 || b != 1)) return false;
    return internalPrimeDivisors(ref, a/ref) &&
           internalPrimeDivisors(ref, b/ref);
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();

    int results = 0;
    for (int i=0; i<size; i++) {
        int num_a = A[i];
        int num_b = B[i];
        if (num_a == num_b) {
            results++;
            continue;
        }
        if (commonPrimeDivisors(num_a, num_b)) results++;
    }
    return results;
}
