// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int possibilities(int num) {
    int result = 1;
    for (int i=0; i<30; i++) {
        int bit = num & (1 << i);
        if (bit == 0) result *= 2;
    }
    return result;
}

int solution(int A, int B, int C) {
    // write your code in C++14 (g++ 6.2.0)
    // the solution:
    // the possibilities of A + B + C - (A|B + B|C + C|A) + A|B|C
    return possibilities(A) + possibilities(B) + possibilities(C)
         - possibilities(A|B) - possibilities(B|C) - possibilities(C|A)
         + possibilities(A|B|C);
}
