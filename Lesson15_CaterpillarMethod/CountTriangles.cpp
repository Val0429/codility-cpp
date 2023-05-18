// you can use includes, for example:
#include <algorithm>
#include <list>

#define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    if (size < 3) return 0;

    /// sort
    std::sort(A.begin(), A.end());

    int total = 0;
    for (int i=0; i<size; i++) {
        int k=i+2;
        for (int j=i+1; j<size; j++) {
            while (k < size && (A[i] + A[j]) > A[k]) {
                k++;
            }
            total += k-j-1;
        }
    }
    return total;
}
