// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    if (size <= 1) return size;

    int total = 1;
    int prev_end = B[0];

    for (int current=1; current<size; current++) {
        if (A[current] > prev_end) {
            total++;
            prev_end = B[current];
        }
    }

    return total;
}