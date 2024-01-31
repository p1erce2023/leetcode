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
    bool valid(vector<int>& nums, int p, int x) {
        int i=0, n=nums.size(), t=0;
        while (i<n) {
            if (i+1 < n && nums[i] + x >= nums[i+1]) {
                t++;
                if (t == p) return true;
                i+=2;
            } else {
                i++;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        // 竟然真的可以用 binary search！从限制来看确实有这层提示，但当时实在没想到二分的解法
        // 感觉是不是很多 min max 的题其实都是 二分 来解？
        if (!p) return 0;
        sort(nums.begin(), nums.end());
        int n=nums.size(), left=0, right=nums[n-1]-nums[0], mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (valid(nums, p, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int minimizeMax2(vector<int>& nums, int p) {
        // dp 就是会 TLE 啊，毕竟 O(pn)，必须要找到 log n的方法
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> d(n-1);
        for (int i=1; i<n; i++) d[i-1] = nums[i] - nums[i-1];
        n--;
        if (p == 1) return *std::min_element(d.begin(), d.end());
        vector<vector<int>> dp(p+1, vector<int>(n+1,1e9));
        dp[0] = vector<int>(n,0);
        dp[1][0] = d[0];
        for (int i=1; i<n; i++) dp[1][i] = min(dp[1][i-1], d[i]);
        int s = d[0], st;
        for (int k=2; k<=p; k++) {
            st = 2*k-2;
            s = max(s, d[st]);
            dp[k][st] = s;
            for (int j=st+1; j<n; j++) {
                dp[k][j] = min(dp[k][j-1], max(d[j], dp[k-1][j-2]));
            }
        }
        int ans = *std::min_element(dp[p].begin(), dp[p].end());
        return ans;
    }
};


int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums; int p;
    nums = {10,1,2,7,1,3}, p = 2;
    std::cout << sol.minimizeMax(nums, p) << std::endl;
    nums = {4,2,1,2}, p = 1;
    std::cout << sol.minimizeMax(nums, p) << std::endl;
    // 3 0 5 7
    // 3 6 6 11 18 p=2, 不能贪心
    nums = {11,6,3,18,6}, p = 2;
    std::cout << sol.minimizeMax(nums, p) << std::endl;
    nums = {4,0,2,1,2,5,5,3}, p = 3;
    // 0 1 2 2 3 4 5 5
    // 1 1 0 1 1 1 0
    std::cout << sol.minimizeMax(nums, p) << std::endl;
    return 0;
}
