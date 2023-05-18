// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    int total = 0;
    int sum = 0;
    for (int i=0; i<size; i++) {
        int current = A[i];
        sum += current;
        if (sum >= K) {
            total++;
            sum = 0;
        }
    }
    return total;
}
