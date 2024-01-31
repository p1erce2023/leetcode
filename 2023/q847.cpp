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
    int shortestPathLength(vector<vector<int>>& e) {
        int n=e.size(), ans=INT_MAX, final_state=0, st, d, nst, mi;
        if (n==1) return 0;
        for (int i=0; i<n; ++i)
            final_state |= 1<<i;
        for (int i=0; i<n; ++i) {
            st = 1<<i;
            vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
            dp[st][i] = 0;
            mi = INT_MAX;
            vector<pair<int,int>> v = {{i, st}};
            while (!v.empty()) {
                vector<pair<int,int>> nv;
                for (auto [x, cst] : v) {
                    d = dp[cst][x];
                    for (int y : e[x]) {
                        nst = cst | 1<<y;
                        if (d+1 < dp[nst][y]) {
                            dp[nst][y] = d+1;
                            if (nst == final_state) {
                                mi = d+1;
                                break;
                            }
                            nv.push_back({y, nst});
                        }
                    }
                    if (mi != INT_MAX) break;
                }
                if (mi != INT_MAX) break;
                v = std::move(nv);
            }
            ans = min(ans, mi);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VVI e;
    e = {{1,2,3},{0},{0},{0}};
    OUT(sol.shortestPathLength(e));
    e = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    OUT(sol.shortestPathLength(e));
    return 0;
}
