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
    string longestPalindrome(string s) {
        // dp[i,j]==1 && dp[i-1]==dp[j+1] -> dp[i-1,j+1]=1
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        string ans;
        for (int i=0; i<n; i++) {dp[i][i]=true; ans=s[i];}
        for (int j=1; j<n; j++)
            for (int i=0; i<n-j; i++) {
                if (s[i] == s[i+j] && (j<2 || dp[i+1][i+j-1])) {
                    dp[i][i+j]=true;
                    ans = s.substr(i,j+1);
                }
            }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "aaaaa";
    OUT(sol.longestPalindrome(s));
    s = "babad";
    OUT(sol.longestPalindrome(s));
    s = "cbbd";
    OUT(sol.longestPalindrome(s));
    return 0;
}
