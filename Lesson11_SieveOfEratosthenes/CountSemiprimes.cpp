// you can use includes, for example:
#include <algorithm>
#include <cmath>

#define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/// O(sqrt(N) * log(log(N)))
vector<bool> arrayF(int n) {
    auto F = vector<bool>(n+1);
    std::fill(F.begin(), F.end(), false);

    int sqrtN = (int)sqrt(n);
    for (int i=2; i<=sqrtN; i++) {
        /// haven't been picked
        if (F[i] == false) {
            for (int j=i*i; j<=n; j+=i) {
                /// mark as multiplies
                if (F[j] == false) {
                    F[j] = true;
                }
            }
        }
    }
    return F;
}
/// O(N + sqrt(N) * log(log(N)))
vector<int> factorF(int n) {
    auto F = arrayF(n);
    auto result = std::vector<int>();
    for (int i=2; i<=n; i++) {
        if (F[i] == false) {
            // DEBUG_MSG("Got factor! " << i);
            result.emplace_back(i);
        }
    }
    return result;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)P.size();
    int lower_bound = N % 2 == 0 ? N/2 : N/3;
    /// O(N + sqrt(N) * log(log(N)))
    vector<int> factors = factorF(lower_bound);
    int factorSize = (int)factors.size();

    /// calculate all the semiprimes
    /// O(N * log(log(N)))
    vector<int> semiprimes;
    for (int i=0; i<factorSize; i++) {
        int factor1 = factors[i];
        for (int j=i; j<factorSize; j++) {
            int factor2 = factors[j];
            int product = factor1 * factor2;
            if (product > N) break;
            semiprimes.emplace_back(product);
        }
    }
    /// O(N * log(N))
    std::sort(semiprimes.begin(), semiprimes.end());

    /// calculate the ladder
    /// O(N)
    auto ladders = vector<int>(N+1);
    std::fill(ladders.begin(), ladders.end(), 0);
    auto it = semiprimes.begin();
    for (int i=2; i<=N; i++) {
        if (it == semiprimes.end()) {
            ladders[i] = ladders[i-1];
            continue;
        }
        ladders[i] = ladders[i-1];
        if (*it == i) {
            ladders[i] = ladders[i-1]+1;
            it++;
        }
        // DEBUG_MSG("Ladder on " << i << " = " << ladders[i]);
    }

    /// O(M)
    auto result = std::vector<int>();
    for (int i=0; i<size; i++) {
        result.emplace_back( ladders[Q[i]] - ladders[P[i]-1] );
    }
    return result;
}
