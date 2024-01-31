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
    int minCut(string s) {
        // dp[j] = min(dp[i] + 1), for i from 0 to j-1, if s[i+1,j] is palindrome
        // O(n^2) if precompute
        int n=s.size(), ii, jj;
        vector<int> dp(n+1,n);
        dp[0] = 0, dp[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) {
                ii=i-1, jj=j;
                while (jj < ii && s[jj] == s[ii]) {jj++, ii--;}
                if (jj >= ii) dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp[n] - 1;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s="aab";
    OUT(sol.minCut(s));
    s="aa";
    OUT(sol.minCut(s));
    s="abcdeffe";
    OUT(sol.minCut(s));
    s="a";
    OUT(sol.minCut(s));
    s="ab";
    OUT(sol.minCut(s));
    s="aaaa";
    OUT(sol.minCut(s));
    s="aabaaccddcc";
    OUT(sol.minCut(s));
    s="aabaa";
    OUT(sol.minCut(s));
    return 0;
}
