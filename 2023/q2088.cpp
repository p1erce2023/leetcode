#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    int countPyramids(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size(), ans=0, x;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (int j=0; j<n; ++j)
            dp[m-1][j] = g[m-1][j];
        for (int i=m-2; i>=0; --i) {
            dp[i][0] = g[i][0];
            for (int j=1; j<n-1; ++j) {
                if (g[i][j]==0) continue;
                dp[i][j] = 1;
                if (g[i+1][j]==0) continue;
                x = min(dp[i+1][j-1], dp[i+1][j+1]);
                if (x) {
                    ans += x;
                    dp[i][j] = x+1;
                }
            }
            dp[i][n-1] = g[i][n-1];
        }
        for (int j=0; j<n; ++j)
            dp[0][j] = g[0][j];
        for (int i=1; i<m; ++i) {
            fill(dp[i].begin(), dp[i].end(), 0);
            dp[i][0] = g[i][0];
            for (int j=1; j<n-1; ++j) {
                if (g[i][j]==0) continue;
                dp[i][j] = 1;
                if (g[i-1][j] == 0) continue;
                x = min(dp[i-1][j-1], dp[i-1][j+1]);
                if (x) {
                    ans += x;
                    dp[i][j] = x+1;
                }
            }
            dp[i][n-1] = g[i][n-1];
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VVI grid;
    grid = {{1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,0,1}};
    OUT(sol.countPyramids(grid));
    return 0;
}
