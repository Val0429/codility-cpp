// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    auto size = A.size();
    if (size == 0) return A;
    size_t times = K % size;
    if (times != 0) {
        for (size_t i=0; i<times; i++) {
            auto it = A.erase(A.end()-1);
            A.insert(A.begin(), *it);
        }
    }
    return A;
}