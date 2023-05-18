// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <chrono>
class PerformanceWatcher {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    PerformanceWatcher() : start(std::chrono::high_resolution_clock::now()) {}
    ~PerformanceWatcher() {
        auto last = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = last - start;
        cout << ms_double.count() << "ms" << endl;
    }
};

int solution(int N) {
    PerformanceWatcher pw;
    {
        // write your code in C++14 (g++ 6.2.0)
        int sqrtN = (int)sqrt(N);
        for (int i=sqrtN; i>0; i--) {
            if (N % i == 0) return (i + N / i) * 2;
        }
        /// should not get here
    }
    return -1;
}
