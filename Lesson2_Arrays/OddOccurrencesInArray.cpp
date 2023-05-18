// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.size() == 0) return -1;
    int result = A[0];
    for (auto it = A.begin(); it != A.end(); it++) {
        result = result ^ (*it);
    }
    return result;
}
