// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int total = 1;
    int pos = 0;
    int value = A[0];
    while (value != -1) {
        pos = value;
        value = A[pos];
        total++;
    }
    return total;
}
