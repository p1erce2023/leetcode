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
    int maxNonOverlapping(vector<int>& nums, int target) {
        int s=0, ans=0, lb=-1;
        unordered_map<int, int> m;
        m[0] = 0;
        for (int i=0; i<nums.size(); i++) {
            s += nums[i];
            auto it=m.find(s-target);
            if (it != m.end() && it->second > lb) {
                lb = i;
                ans++;
            }
            m[s] = i+1;
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums; int target;
    nums = {1,1,1,1,1}, target = 2;
    std::cout << sol.maxNonOverlapping(nums,target) << std::endl;
    nums = {1,1,1,1,1}, target = 1;
    std::cout << sol.maxNonOverlapping(nums,target) << std::endl;
    nums = {1,1,1,2,1,1}, target = 3;
    std::cout << sol.maxNonOverlapping(nums,target) << std::endl;
    nums = {2,1,1,1,2,2,1}, target = 3;
    std::cout << sol.maxNonOverlapping(nums,target) << std::endl;
    nums = {-1,3,5,1,4,2,-9}, target = 6;
    std::cout << sol.maxNonOverlapping(nums,target) << std::endl;
    nums = {1,2,2,-1,-3,1,1,2,1,3}, target = 3;
    std::cout << sol.maxNonOverlapping(nums,target) << std::endl;
    return 0;
}
