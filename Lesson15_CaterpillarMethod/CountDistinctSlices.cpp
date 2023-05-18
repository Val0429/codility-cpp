// you can use includes, for example:
// #include <algorithm>

//#define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int head = 0, tail = 0;
    auto counters = std::vector<int>(M+1, 0);
    int size = (int)A.size();
    int total = 0;
    while (tail < size) {
        while (head < size && counters[A[head]] < 2) {
            DEBUG_MSG("Head at: " << head << ", value: " << A[head] << ".");
            counters[A[head]]++;
            if (counters[A[head]] == 2) break;
            head++;
        }
        total += head - tail;
        if (total >= 1000000000) return 1000000000;
        DEBUG_MSG("Tail at: " << tail << ", total: " << total);
        counters[A[tail]] = 0;
        tail++;
    }
    return total;
}
