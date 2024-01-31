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
    bool isValid(vector<int>& nums, int x) {
        long long s = 0;
        for (int i=nums.size()-1; i>-1; i--) {
            if (nums[i] > x) {
                s += nums[i] - x;
            } else if (s > 0) {
                s = max(s - (x - nums[i]), 0ll);
            }
        }
        return !s;
    }

    int minimizeArrayValue2(vector<int>& nums) {
        // O(nlog(n))
        int left=0, right=1e9, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (isValid(nums, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int minimizeArrayValue(vector<int>& nums) {
        // O(n)
        long long s=nums[0];
        int ans=nums[0], m=nums[0];
        for (int i=1; i<nums.size(); i++) {
            s += nums[i];
            if (nums[i] <= m) continue;
            m = s/(i+1) + ((s%(i+1))!=0 ? 1:0);
            ans = max(ans, m);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums;
    nums = {10,1};
    std::cout << sol.minimizeArrayValue(nums) << std::endl;
    nums = {3,7,1,6};
    std::cout << sol.minimizeArrayValue(nums) << std::endl;
    return 0;
}
