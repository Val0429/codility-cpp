// var dynamic_coin_changing = (C, k) => {
//     var n = C.length;
    
//     /// multi-dimensional array
//     var rows = n+1;
//     var cols = k+1;
//     var dp = new Array();
//     for (var i=0; i<rows; i++) {
//        dp[i] = new Array();
//        for (var j=0; j<cols; j++) {
//           dp[i][j] = i == 0 && j != 0 ? Number.MAX_SAFE_INTEGER : 0;
//        }
//     }
 
//     for (var i=1; i<rows; i++) {
//        for (var j=0; j<C[i-1]; j++) {
//           console.log(`dp[${i}][${j}] = dp[${i-1}][${j}] = ${dp[i-1][j]}`);
//           dp[i][j] = dp[i-1][j];
//        }
//        for (var j=C[i-1]; j<cols; j++) {
//           console.log(`dp[${i}][${j}] = min(${dp[i][j-C[i-1]] + 1}, ${dp[i-1][j]})`);
//           dp[i][j] = Math.min(dp[i][j-C[i-1]] + 1, dp[i-1][j]);
//        }
//     }
//     return dp;
//  }
//  dynamic_coin_changing([1,3,4], 6);

// var dynamic_coin_changing2 = (C, k) => {
//     var n = C.length;
   
//     /// multi-dimensional array
//     var rows = n+1;
//     var cols = k+1;
//     var dp = new Array();
//     for (var j=0; j<cols; j++) {
//         dp[j] = j == 0 ? 0 : Number.MAX_SAFE_INTEGER;
//     }

//     for (var i=1; i<rows; i++) {
//         for (var j=C[i-1]; j<cols; j++) {
//             console.log(`dp[${j}] = min(${dp[j-C[i-1]] + 1}, ${dp[j]})`);
//             dp[j] = Math.min(dp[j-C[i-1]] + 1, dp[j]);
//         }
//     }
//     return dp;
// }
// dynamic_coin_changing2([1,3,4], 6);

// var frog = (S, distance, q) => {
//     var size = S.length;
//     var dp = new Array();
//     dp[0] = 1;
//     for (var i=1; i<=distance; i++) dp[i] = 0;
//     for (var dis=1; dis<distance+1; dis++) {
//         console.log(`Distance ${dis}!`);
//         for (var st=0; st<size; st++) {
//             console.log(`Measure step ${S[st]}`);
//             if (S[st] <= dis) {
//                 console.log(`dp[${dis}] = dp[${dis}] + dp[${dis}-${S[st]}] = (${dp[dis]} + ${dp[dis-S[st]]}) = ${(dp[dis] + dp[dis-S[st]]) % q}`);
//                 dp[dis] = (dp[dis] + dp[dis-S[st]]) % q;
//             }
//         }
//     }
//     return dp[distance];
// };
// frog([1,2,4], 6, Number.MAX_SAFE_INTEGER);


// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    std::vector<int> dp(size, std::numeric_limits<int>::min());
    dp[0] = A[0];

    int diceSize = 6;
    std::vector<int> dice(diceSize);
    for (int i=1; i<=diceSize; i++) dice[i-1] = i;

    for (int i=1; i<size; i++) {
        int curPoint = A[i];
        cout << "measure point: " << i << ", " << curPoint << endl;
        for (int j=0; j<diceSize; j++) {
            int diceNum = dice[j];
            if (diceNum <= i) {
                cout << "replace dp[i]: " << dp[i] << ", " << (dp[i-diceNum] + curPoint) << endl;
                dp[i] = std::max(
                    dp[i],
                    dp[i-diceNum] + curPoint
                    );
            }
        }
    }

    cout << "the dp!" << endl;
    for (auto it = dp.begin(); it != dp.end(); it++) {
        cout << *it << endl;
    }

    return dp[size-1];
}
