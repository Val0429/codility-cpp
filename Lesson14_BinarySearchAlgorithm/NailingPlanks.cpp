// you can use includes, for example:
#include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

class Plank {
public:
    int left;
    int right;
    Plank(int left, int right): left(left), right(right) {}
};

class Nail {
public:
    int pos;
    int originalIdx;
    Nail(int pos, int originalIdx): pos(pos), originalIdx(originalIdx) {}
};

int getMinIndex(const Plank& plank, const std::vector<Nail>& nails, int refResult) {
    int nailSize = (int)nails.size();
    int min = 0;
    int max = nailSize-1;
    
    int minIdx = -1;
    while (min <= max) {
        int mid = (min+max)/2;
        const Nail& nail = nails[mid];
        if (plank.left > nail.pos) {
            min = mid + 1;
        } else if (plank.right < nail.pos) {
            max = mid - 1;
        } else {
            minIdx = mid;
            max = mid - 1;
        }
    }

    if (minIdx == -1) return -1;
    int result = nails[minIdx].originalIdx;
    if (result <= refResult) return refResult;
    for (int i=minIdx; i<nailSize; i++) {
        if (nails[i].pos > plank.right) break;
        const Nail& nail = nails[i];
        result = std::min(result, nail.originalIdx);
        /// cannot be less than ref result
        if (result <= refResult) return refResult;
    }
    return result;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)

    /// aggregate the planks
    auto planks = std::vector<Plank>();
    int plankSize = (int)A.size();
    for (int i=0; i<plankSize; i++) {
        planks.emplace_back(Plank(A[i], B[i]));
    }

    /// aggregate the nails
    auto nails = std::vector<Nail>();
    int nailSize = (int)C.size();
    for (int i=0; i<nailSize; i++) {
        nails.emplace_back(Nail(C[i], i));
    }
    /// sort the nails ascendant
    std::sort(nails.begin(), nails.end(), [](const Nail& a, const Nail& b) {
        int pos = b.pos - a.pos;
        int idx = b.originalIdx - a.originalIdx;
        if (pos == 0) return idx > 0;
        return pos > 0;
    });

    /// find all the planks
    int result = -1;
    for (auto it = planks.begin(); it != planks.end(); it++) {
        result = getMinIndex(*it, nails, result);
        if (result == -1) return result;
    }
    return result == -1 ? result : result + 1;
}
