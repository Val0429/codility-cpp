// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    // the idea:
    // from bit 29 to 0, 
    // 1) if current bit = 0, continue.
    // 2) if current bit = 1, check current bit / previous bit to place it.
    int sparse1 = 0;
    int sparse2 = 0;
    for (int i=29; i>=0; i--) {
        int previousBit = 1<<(i+1);
        int currentBit = 1<<i;
        // 1)
        bool isCurrentBit1 = (N & currentBit) != 0;
        if (!isCurrentBit1) continue;

        // 2)
        bool isSpase1Current1 = (sparse1 & currentBit) != 0;
        bool isSpase2Current1 = (sparse2 & currentBit) != 0;
        bool isSparse1Previous1 = (sparse1 & previousBit) != 0;
        bool isSparse2Previous1 = (sparse2 & previousBit) != 0;

        /// it's already full
        if (isSpase1Current1 && isSpase2Current1) return -1;

        /// put into sparse1
        if (!isSpase1Current1 && !isSparse1Previous1) {
            sparse1 |= currentBit;
            cout << "put into sparse1! " << i << ", " << sparse1 << endl;
            continue;
        }
        /// put into sparse2
        if (!isSpase2Current1 && !isSparse2Previous1) {
            sparse2 |= currentBit;
            cout << "put into sparse2! " << sparse2 << endl;
            continue;
        }

        /// put into next digit
        if (!isSpase1Current1 && !isSpase2Current1 && i > 0) {
            int nextBit = 1<<(i-1);
            sparse1 |= nextBit;
            sparse2 |= nextBit;
            cout << "put into next digit! " << sparse1 << ", " << sparse2 << endl;
            continue;
        }

        /// failed to insert
        return -1;
    }
    return sparse1;
}
