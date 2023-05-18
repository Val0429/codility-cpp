// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int totalFactors = 1;
    int factor = 1;
    int count = 0;
    int i = 2;
    while (N != 1) {
        if (N % i == 0) {
            if (factor != i) {
                totalFactors *= count+1;
                factor = i;
                count = 0;
            }
            count++;
            N = N / i;
        } else {
            if (i == 2) i += 1;
            else i += 2;
        }
    }
    totalFactors *= count+1;
    return totalFactors;
}
