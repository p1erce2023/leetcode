#include <unordered_map>
#include <vector>
#include <iostream>
using std::vector;
using std::unordered_map;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> s = {{0, 1}};
        int x = 0;
        long long r = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            x = x xor nums[i];
            // std::cout << x << std::endl;
            if (s.find(x) == s.end())
                s[x] = 1;
            else
                s[x] += 1;
        }
        for (auto [k, v] : s) {
            // std::cout << k << ' ' << v << std::endl;
            if (v > 1) {
                r += static_cast<long long>(v) * (v-1) / 2;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,3,1,2,4};
    std::cout << s.beautifulSubarrays(nums) << std::endl;
    return 0;
}