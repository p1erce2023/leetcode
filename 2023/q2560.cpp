#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::priority_queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    bool is_valid(int c, vector<int>& nums, int k) {
        // greedy 精彩！
        int t = k;
        bool last_is_stolen = false;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] <= c && !last_is_stolen) {
                t--;
                last_is_stolen = true;
                if (!t) return true;
            } else {
                last_is_stolen = false;
            }
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = 1e9, right = 1;
        for (int x : nums) {
            left = min(left, x);
            right = max(right, x);
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (is_valid(mid, nums, k))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int minCapability2(vector<int>& nums, int k) {
        /* TLE
        dp[1,i] = min(nums[i] -> nums[n-1])
        dp[2,i] = min(max(nums[i], dp[1,i-2]); i from n-3 to 0)
        O(k * n) 有点大
        */
        int n = nums.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        dp[1][1] = nums[0];
        for (int i=1; i<n; i++) {
            dp[1][i+1] = min(dp[1][i], nums[i]);
        }
        int js;
        for (int i=2; i<=k; i++) {
            js = 2*i-1;
            dp[i][js] = max(dp[i-1][js-2], nums[js-1]);
            for (int j=js+1; j<=n; j++) {
                dp[i][j] = min(dp[i][j-1], max(dp[i-1][j-2], nums[j-1]));
            }
        }
        int ans = 1e9+1;
        for (int i=2*k-1; i<=n; i++)
            ans = min(ans, dp[k][i]);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums;
    int k;
    nums = {2,3,5,9}, k = 2;
    std::cout << sol.minCapability(nums, k) << ' ' << sol.minCapability2(nums, k) << std::endl;
    nums = {2,7,9,3,1}, k = 2;
    std::cout << sol.minCapability(nums, k) << ' ' << sol.minCapability2(nums, k) << std::endl;
    return 0;
}
