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
using std::accumulate;
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
    int dp[30][30][31];
    int f(int i, int j, int t, int k, VI& A) {
        if (dp[i][j][t] != -1) return dp[i][j][t];
        int ans = INT_MAX;
        if (t==1) {
            int s = accumulate(A.begin()+i, A.begin()+j+1, 0);
            if (i==j) return 0;
            if (i+k-1==j) return s;
            for (int x=i; x<=j-k+1; x += (k-1))
                ans = min(ans, f(i, x, 1, k, A) + f(x+1, j, k-1, k, A));
            return dp[i][j][t] = ans + s;
        } else {
            for (int x=i; x<=j-t+1; x += (k-1))
                ans = min(ans, f(i, x, 1, k, A) + f(x+1, j, t-1, k, A));
            return dp[i][j][t] = ans;
        }
    }
    int mergeStones(vector<int>& A, int k) {
        int n=A.size();
        if (k!=2 && n%(k-1)!=1) return -1;
        memset(dp, -1, sizeof(dp));
        return f(0, n-1, 1, k, A);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI stones; int k;
    stones = {3,2,4,1}, k = 2;
    OUT(sol.mergeStones(stones, k));
    stones = {3,2,4,1}, k = 3;
    OUT(sol.mergeStones(stones, k));
    stones = {3,5,1,2,6}, k = 3;
    OUT(sol.mergeStones(stones, k));
    return 0;
}
