#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::string;
using std::vector;
using std::queue;
using std::priority_queue;
using std::set;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::max;
using std::min;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size(), ss=0;
        vector<int> dp(k+1,0), ndp(k+1,0);
        for (int j=0; j<k; j++) {
            if (j<piles[0].size()) ss += piles[0][j];
            dp[j+1] = ss;
        }
        ndp = dp;
        for (int i=1; i<n; i++) {
            ss = 0;
            for (int x=0; x<min(k,static_cast<int>(piles[i].size())); x++) {
                ss += piles[i][x];
                for (int j=1+x; j<=k; j++) {
                    ndp[j] = max(ndp[j], dp[j-x-1] + ss);
                }
            }
            dp = ndp;
        }
        return dp[k];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> piles; int k;
    piles = {{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}}, k = 7;
    std::cout << sol.maxValueOfCoins(piles, k) << std::endl;
    piles = {{1,100,3},{7,8,9}}, k = 2;
    std::cout << sol.maxValueOfCoins(piles, k) << std::endl;
    return 0;
}

// 几轮优化之后，总算到了 beat 99%