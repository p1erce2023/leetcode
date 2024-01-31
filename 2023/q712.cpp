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
    int minimumDeleteSum(string s1, string s2) {
        // dp[i][j] = s1[i] + dp[i-1][j-1], if s1[i] == s2[j]      
        int n1=s1.size(), n2=s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for (int i=0; i<n1; ++i)
            for (int j=0; j<n2; ++j)
                if (s1[i] == s2[j]) 
                    dp[i+1][j+1] = max(dp[i+1][j+1], s1[i] + dp[i][j]);
                else
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        int c1=std::accumulate(s1.begin(), s1.end(), 0), c2=std::accumulate(s2.begin(), s2.end(), 0);
        return c1 + c2 - 2 * dp[n1][n2];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s1, s2;
    s1 = "sea", s2 = "eat";
    OUT(sol.minimumDeleteSum(s1, s2));
    s1 = "delete", s2 = "leet";
    OUT(sol.minimumDeleteSum(s1, s2));
    return 0;
}
