// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool divisionSolvable(int mid, int K, vector<int> A) {
    int sum = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        int value = *it;
        sum += value;
        if (sum > mid) {
            sum = value;
            K--;
        }
        if (K == 0) return false;
    }
    return true;
}

int solution(int K, int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int min = 0;
    int max = 0;
    int size = (int)A.size();

    /// get the possible min / max of result
    for (int i=0; i<size; i++) {
        max += A[i];
        min = std::max(min, A[i]);
    }

    int result = max;
    while (min <= max) {
        int mid = (max + min) / 2;
        if (divisionSolvable(mid, K, A)) {
            max = mid - 1;
            result = mid;
        } else {
            min = mid + 1;
        }
    }
    return result;
}
