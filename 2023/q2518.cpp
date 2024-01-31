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
    int countPartitions(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // for (auto vi : nums) { std::cout << vi << ' '; }
        // std::cout << std::endl;
        int tt=1, MOD=1e9+7, ans, res, res2=0;
        long long s=0;
        vector<int> dp(k,0);
        dp[0] = 1;
        for (int x : nums) {
            s += x;
            tt = (2ll * tt) % MOD;
            for (int i=k-x-1; i>-1; i--) {
                if (dp[i]) dp[i+x] = (dp[i]+dp[i+x]) % MOD;
            }
        }
        if (s < 2*k) {
            for (int i=max(s-k+1,0ll); i<k; i++) res2 += dp[i];
        }
        res = std::accumulate(dp.begin(), dp.end(), 0);
        ans = (0ll + tt - 2*res + res2 + MOD) % MOD;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums; int k;
    nums= {73,16,86,25,98,92,15,11,87,88,88,94,83,74,1,48,91,9,45}, k=61;
    std::cout << sol.countPartitions(nums,k) << std::endl;
    nums = {1,2,3,4}, k = 6;
    std::cout << sol.countPartitions(nums,k) << std::endl;
    nums = {1,2,3,4}, k = 4;
    std::cout << sol.countPartitions(nums,k) << std::endl;
    nums = {3,3,3}, k = 4;
    std::cout << sol.countPartitions(nums,k) << std::endl;
    nums = {6,6}, k = 2;
    std::cout << sol.countPartitions(nums,k) << std::endl;
    nums = {1,2}, k = 6;
    std::cout << sol.countPartitions(nums,k) << std::endl;
    return 0;
}
