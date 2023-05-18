// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int pass_east = 0;
    int pass = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        int val = *it;
        if (val == 0) {
            pass_east++;
        } else {
            pass += pass_east;

            if (pass > 1000000000 || pass < 0) return -1;
        }
    }
    return pass;
}
