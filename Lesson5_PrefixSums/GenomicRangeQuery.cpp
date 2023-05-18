// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    auto len = S.length();
    auto size = P.size();
    auto result = std::vector<int>(size);
    auto A = std::vector<int>(len+1);
    auto C = std::vector<int>(len+1);
    auto G = std::vector<int>(len+1);
    auto T = std::vector<int>(len+1);
    A[0] = 0;
    C[0] = 0;
    G[0] = 0;
    T[0] = 0;
    for (size_t i=0; i<len; i++) {
        char chr = S[i];
        if (chr == 'A') {
            A[i+1] = A[i]+1;
            C[i+1] = C[i];
            G[i+1] = G[i];
            T[i+1] = T[i];
        } else if (chr == 'C') {
            A[i+1] = A[i];
            C[i+1] = C[i]+1;
            G[i+1] = G[i];
            T[i+1] = T[i];
        } else if (chr == 'G') {
            A[i+1] = A[i];
            C[i+1] = C[i];
            G[i+1] = G[i]+1;
            T[i+1] = T[i];
        } else if (chr == 'T') {
            A[i+1] = A[i];
            C[i+1] = C[i];
            G[i+1] = G[i];
            T[i+1] = T[i]+1;
        }
    }

    for (size_t i=0; i<size; i++) {
        int qpos = Q[i];
        int ppos = P[i];
        if (A[qpos+1] - A[ppos] > 0) {
            result[i] = 1;
            continue;
        } else if (C[qpos+1] - C[ppos] > 0) {
            result[i] = 2;
            continue;
        } else if (G[qpos+1] - G[ppos] > 0) {
            result[i] = 3;
            continue;
        }
        result[i] = 4;
    }

    return result;
}
