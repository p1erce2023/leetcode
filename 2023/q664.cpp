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

using UMPII = unordered_map<int,int>;
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;

class Solution {
public:
    int dp[101][101];
    int f(int i, int j, string& s) {
        if (i+1 == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int ans=j-i;
        for (int k=i+1; k<j; ++k)
            ans = min(ans, f(i,k,s) + f(k,j,s) - (s[i] == s[j-1]? 1 : 0));
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        s.erase(std::unique(s.begin(), s.end()), s.end());
        memset(dp, -1, sizeof(dp));
        return f(0, s.size(), s);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "aaabbb";
    OUT(sol.strangePrinter(s));
    s = "aba";
    OUT(sol.strangePrinter(s));
    s = "abcdeeeeaaadcxb";
    OUT(sol.strangePrinter(s));
    s = "abcabcabc";
    OUT(sol.strangePrinter(s));
    s = "acbdadbc";
    OUT(sol.strangePrinter(s));
    return 0;
}
