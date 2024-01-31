#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <utility>
using std::vector;
using std::pair;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    int func(unordered_map<int, int>& c) {
        if (c.size() == 1) return (1 << c.begin()->second) - 1;
        vector<vector<int>> items;
        for (auto [k, v] : c) {
            items.push_back({k, v});
        }
        std::sort(items.begin(), items.end());
        int n = items.size();
        vector<int> s(n + 1, 0);
        s[0] = 0;
        s[1] = (1 << items[0][1]) - 1;
        for (int i = 1; i < items.size(); i++) {
            s[i+1] = (s[i-1] + 1) * ((1 << items[i][1]) - 1) + s[i];
        }
        return s[n];
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> c, cc; // counter
        for (int x : nums) {
            if (c.find(x) == c.end()) c[x] = 1;
            else c[x]++;
        }
        unordered_set<int> seen;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i], t;
            if (seen.find(x) != seen.end()) continue;
            seen.insert(x);
            cc[x] = c[x];
            t = x - k;
            while (c.find(t) != c.end()) {
                cc[t] = c[t];
                seen.insert(t);
                t -= k;
            }
            t = x + k;
            while (c.find(t) != c.end()) {
                cc[t] = c[t];
                seen.insert(t);
                t += k;
            }
            ans *= 1 + func(cc);
            cc.clear();
        }
        return ans - 1;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums = {2,4,6};
    // std::cout << s.beautifulSubsets(nums, 2) << std::endl;
    // nums = {1};
    // std::cout << s.beautifulSubsets(nums, 1) << std::endl;
    nums = {4,2,5,9,10,3};
    std::cout << s.beautifulSubsets(nums, 1) << std::endl;
    return 0;
}
/*
k = 2, [2 4 6]
[2]
[4]
[6]
[2 6]
a3 = max(a1 * 2, a2)

[2 4 4 6]
{2 4:2 6}
{2:3 4:2}
[2] [2] [2] [2 2] [2 2] [2 2] [2 2 2] [4] [4] [4 4]
a[0]=1 * 2^2 - 1 + a[1] * 2^3 - 1

[a0+k, a0+2*k, ..., a0+n*k]
[2 4 6 8]
[2] [4] [6] [8]
[2 6] [2 8] [4 8]
[]

[2 4]
[2] [4]

[2 4 4]
[2] [4] [4]

[2 4 4 6]
[2] [4] [4] [6] [2 6]

a_n = a_n-1 + a_n-2
a1 = 2
a2 = 3
a3 = 5
a4 = 8
*/