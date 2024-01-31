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
    // 经典DP
    int numWays(vector<string>& words, string target) {
        int n=words[0].size(),m=target.size(),MOD=1e9+7;
        vector<vector<int>> vc(n, vector<int>(26,0));
        vector<int> dp(n+1,0), ndp(n+1,0);
        for (string& w : words) {
            for (int i=0; i<w.size(); i++) {
                vc[i][w[i]-'a']++;
            }
        }
        for (int j=0; j<m; j++) {
            for (int i=0; i<j; i++) ndp[i+1] = 0;
            for (int i=j; i<n; i++) {
                ndp[i+1] = (1ll*(j==0? 1 : dp[i])*vc[i][target[j]-'a']+ndp[i]) % MOD;
            }
            swap(dp, ndp);
        }
        return dp[n];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> words; string target;
    words = {"abba","baab"}, target = "bab";
    std::cout << sol.numWays(words, target) << std::endl;
    words = {"acca","bbbb","caca"}, target = "aba";
    std::cout << sol.numWays(words, target) << std::endl;
    words = {"baac","dbac","baaa","bdcc","cacc"}, target = "abc";
    std::cout << sol.numWays(words, target) << std::endl;
    return 0;
}
