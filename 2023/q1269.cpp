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
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    int MOD=1e9+7;
    int numWays(int k, int n) {
        int m=min(n, k/2+1);
        vector<int> dp(m);
        dp[0] = 1;
        for (int i=0; i<k; ++i) {
            vector<int> ndp(m);
            for (int j=0; j<m; ++j) {
                if (dp[j]) {
                    if (j) ndp[j-1] = (ndp[j-1] + dp[j]) % MOD;
                    ndp[j] = (ndp[j] + dp[j]) % MOD;
                    if (j<m-1) ndp[j+1] = (ndp[j+1] + dp[j]) % MOD;
                }
            }
            swap(dp, ndp);
        } 
        return dp[0];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int k, n;
    k = 3, n = 2;
    OUT(sol.numWays(k, n));
    return 0;
}
