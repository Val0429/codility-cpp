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