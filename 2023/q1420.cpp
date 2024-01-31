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
const int MOD=1e9+7, MX=51;
int mult(int a, int b) { return (1ll*a*b) % MOD; }
int fact[MX], inv[MX], invfact[MX];
void init_INV() {
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < MX; ++i) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[MOD % i], MOD - MOD / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
int ncr(int n, int r) {
    if (r > n) return 0;
    return (1LL * fact[n] * invfact[n-r] % MOD) * 1LL * invfact[r] % MOD;
}
class Solution {
public:
    int dp[51][51][101];
    int f(int n, int k, int x) {
        if (n == k)
            return ncr(x-1, k-1);
        if (dp[n][k][x] != -1) 
            return dp[n][k][x];
        int ans = (1ll * f(n-1, k, x) * x) % MOD;
        if (k>1) {
            for (int xx=k-1; xx<x; ++xx)
                ans = (ans + f(n-1, k-1, xx)) % MOD;
        }
        return dp[n][k][x] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        if (k==0) return 0;
        init_INV();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int x=k; x<=m; ++x)
            ans = (ans + f(n, k, x)) % MOD;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n, m, k;
    n = 2, m = 3, k = 1;
    OUT(sol.numOfArrays(n, m, k));
    return 0;
}
