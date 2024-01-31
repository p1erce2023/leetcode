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
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD=1e9+7,m=group.size(),ans=0;
        // i个任务,j个人,k的profit有多少种组合
        using vvi = vector<vector<int>>;
        using vi = vector<int>;
        vvi dp(n+1, vi(minProfit+1,0)), ndp(n+1, vi(minProfit+1,0));
        dp[0][0] = ndp[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<=n-group[i]; j++) {
                for (int k=0; k<=minProfit; k++) {
                    int& c = ndp[j+group[i]][min(minProfit,k+profit[i])];
                    c = (0ll + c + dp[j][k]) % MOD;
                }
            }
            dp = ndp;
        }
        for (int i=0;i<=n;i++) ans = (ans+dp[i][minProfit]) % MOD;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n; int minProfit; vector<int> group; vector<int> profit;
    n = 5, minProfit = 3, group = {2,2}, profit = {2,3};
    std::cout << sol.profitableSchemes(n,minProfit,group,profit) << std::endl;
    n = 10, minProfit = 5, group = {2,3,5}, profit = {6,7,8};
    std::cout << sol.profitableSchemes(n,minProfit,group,profit) << std::endl;
    return 0;
}
