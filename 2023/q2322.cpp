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
using std::array;
using std::deque;
using std::string;
using std::vector;
using std::queue;
using std::priority_queue;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::max;
using std::min;
using std::next;
using std::distance;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using UMPII = unordered_map<int,int>;
class Solution {
public:
    int dfs(int x, int p, int& c, VI& dp, VI& contain, VI& A, VVI& e) {
        int eid, val=A[x];
        for (int nx : e[x]) {
            if (nx == p) continue;
            eid = c++;
            dp[eid] = dfs(nx, x, c, dp, contain, e);
            contain[eid] = c;  // ), not include
            val ^= dp[eid];
        }
        return val;
    }
    int minimumScore(vector<int>& A, vector<vector<int>>& edges) {
        int n=A.size();
        vector<vector<int>> e(n, vector<int>());
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        vector<int> dp(n), contain(n);
        int tt = dfs(0, -1, 0, dp, contain, A, e), p1, p2, p3, ans=INT_MAX;
        for (int i=0; i<n-1; ++i)
            for (int j=i+1; j<n-1; ++j) {
                if (contain[i] > j) {
                    p1 = tt ^ dp[i];
                    p2 = dp[i] ^ dp[j];
                    p3 = dp[j];
                } else {
                    p1 = dp[i];
                    p2 = dp[j];
                    p3 = tt ^ dp[i] ^ dp[j];
                }
                ans = min(ans, max({p1,p2,p3}) - min({p1,p2,p3}));
            }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
