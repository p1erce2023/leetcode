#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
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

class Solution {
public:
    int lcs2(string& s, string& t) {
        int n=s.size();
        vector<int> dp(n+1,0), ndp(n+1,0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (s[i] == t[j]) {
                    ndp[j+1] = dp[j] + 1;
                } else {
                    ndp[j+1] = max(ndp[j],dp[j+1]);
                }
            }
            swap(dp, ndp);
        }
        return dp[n];
    }

    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        return lcs2(s,t);
    }
};
// bbbab
// babbb
// dp[i][j]

// cbbd
// dbbc

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "bbbab";
    std::cout << sol.longestPalindromeSubseq(s) << std::endl;
    return 0;
}