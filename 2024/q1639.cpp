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
    int numWays(vector<string>& A, string T) {
        int MOD = 1e9 + 7, n = T.size(), m = A[0].size();
        vector<array<int, 26>> d(m);
        for (auto& s : A) {
            for (int i=0; i<m; ++i)
                d[i][s[i]-'a']++;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        std::fill(dp[n].begin(), dp[n].end(), 1);
        // dp[n][m] = 1;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                dp[n-1-i][m-1-j] = (dp[n-1-i][m-j] +  1ll * dp[n-i][m-j] * d[m-1-j][T[n-1-i] - 'a']) % MOD;
            }
        }
        // dp[i][k] = dp[i+1][k+1] * x + dp[i][k+1];
        return dp[0][0];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> A;
    // = {"acca","bbbb","caca"};
    string T;
    //  = "aba";
    A = {"abba","baab"};
    T = "bab";
    OUT(sol.numWays(A, T));
}
