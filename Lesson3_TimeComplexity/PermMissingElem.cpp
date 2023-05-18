// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t size = A.size();
    //if (size == 0) return 1;
    double newSize = (double)size+1;
    size_t total = (size_t)((newSize+1)*(newSize/2));

    for (auto it = A.begin(); it != A.end(); it++) {
        total -= *it;
    }
    return total;
}
