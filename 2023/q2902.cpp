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
    int countSubMultisets(vector<int>& A, int l, int r) {
        vector<int> dp(2e4+1);
        dp[0] = 1;
        unordered_map<int, int> mp;
        for (int a : A)
            mp[a]++;
        if (mp.count(0)) {
            dp[0] += mp[0];
            mp.erase(0);
        }
        for (auto [k, v] : mp) {
            for (int i=0, x, dx; i<k; ++i) {
                x = r-i;
                if (x < 0) continue;
                dx = 0;
                for (int j=1; j<=v; ++j)
                    if (x-j*k>=0)
                        dx = (dx + dp[x-j*k]) % MOD;
                while (1) {
                    dp[x] = (dp[x] + dx) % MOD;
                    x -= k;
                    if (x < 0) break;
                    dx = (0ll + dx + MOD + (x-v*k>=0? dp[x-v*k] : 0) - dp[x]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i=l; i<=r; ++i)
            ans = (ans + dp[i]) % MOD;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI A; int l, r;
    // A = {1,2,2,3}, l=6, r=6;
    // OUT(sol.countSubMultisets(A, l, r));
    // A = {2,1,4,2,7}, l=1, r=5;
    // OUT(sol.countSubMultisets(A, l, r));
    // A = {1,2,1,3,5,2}, l=3, r=5;
    // OUT(sol.countSubMultisets(A, l, r));
    A = {0,0,1,2,3}, l=2, r=3;
    OUT(sol.countSubMultisets(A, l, r));
    return 0;
}
