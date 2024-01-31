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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    int paintWalls(vector<int>& C, vector<int>& T) {
        int n=C.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=0; i<n; ++i)
            for (int j=n, lj; j>=0; --j) {
                lj = max(j-T[i]-1,0);
                if (dp[lj] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[lj]+C[i]);
            }
        return dp[n];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> C, T;
    C = {1,2,3,2}, T = {1,2,3,2};
    OUT(sol.paintWalls(C,T));
    C = {2,3,4,2}, T = {1,1,1,1};
    OUT(sol.paintWalls(C,T));
    C = {42,8,28,35,21,13,21,35}, T = {2,1,1,1,2,1,1,2};
    OUT(sol.paintWalls(C,T));
    return 0;
}
