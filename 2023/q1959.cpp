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
    int dp[201][201];
    int vma[201][201];
    int vs[201][201];

    int f(int m, int i, vector<int>& A) {
        int n=A.size();
        if (i == n) return 0;
        if (m == 1)
            return vma[i][n-1] * (n-i) - vs[i][n-1];
        if (dp[m][i] != -1)
            return dp[m][i];
        int ans = INT_MAX;
        for (int j=i, x; j<n; ++k) {
            x = vma[i][j] * (j-i+1) - vs[i][j];
            ans = min(ans, x + f(m-1,j+1,A));
        }
        return dp[m][i] = ans;
    }
    int minSpaceWastedKResizing(vector<int>& A, int k) {
        int n=A.size(), ma, s;
        memset(vma, 0, sizeof(vma));
        memset(vs, 0, sizeof(vs));
        for (int i=0; i<n; ++i) {
            ma = 0, s = 0;
            for (int j=i; j<n; ++j) {
                ma = max(ma, A[j]);
                s += A[j];
                vs[i][j] = s;
                vma[i][j] = ma;
            }
        }
        memset(dp, -1, sizeof(dp));
        return f(k+1, 0, A);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
