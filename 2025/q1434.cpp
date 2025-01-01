#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VVI = vector<vector<int>>;
using LL = long long;
using VI = vector<int>;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size(), MOD = 1e9+7;
        vector<vector<int>> dp(41, vector<int>(1<<n, 0));
        dp[0][0] = 1;
        vector<vector<int>> hmp(41);
        for (int i=0; i<n; ++i) {
            for (auto h : hats[i]) {
                hmp[h].push_back(i);
            }
        }
        for (int i=1; i<=40; ++i) {
            dp[i] = dp[i-1];
            for (auto p : hmp[i]) {
                for (int state=0; state < (1<<n); ++state) {
                    if (state & (1<<p)) continue;
                    dp[i][state | (1<<p)] = (dp[i][state | (1<<p)] + dp[i-1][state]) % MOD;
                }
            }

        }
        return dp[40][(1<<n) - 1];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> hats = {{3,5,1},{3,5}};
    OUT(sol.numberWays(hats));
}

// switch dimensions for DP