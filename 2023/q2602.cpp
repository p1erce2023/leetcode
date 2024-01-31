#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#include <numeric>
using std::priority_queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;

class Solution {
public:
    int bisect(int x, vector<int>& nums) {
        int i = 0, j = nums.size(), mid;
        if (x <= nums[0]) return 0;
        else if (x > nums[j - 1]) return j;
        else {
            while (i < j) {
                mid = (i + j) >> 1;
                if (x == nums[mid]) return mid;
                else if (x < nums[mid]) {
                    j = mid;
                } else {
                    i = mid + 1;
                }
            }
            return i;
        }
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = queries.size(), q, idx, diff;
        vector<long long> s(n, -1), ans(m);
        s[0] = std::accumulate(nums.begin(), nums.end(), 0ll) - 1ll * n * nums.front();
        for (int i=1; i<n; i++) {
            s[i] = 0ll + s[i - 1] + 1ll * (i - (n-i)) * (nums[i] - nums[i-1]);
        }
        for (int i=0; i<m; i++) {
            q = queries[i];
            idx = bisect(q, nums);
            if (idx > 0) {
                ans[i] = 0ll + s[idx - 1] + 1ll * (idx - (n-idx)) * (q - nums[idx - 1]);
            } else {
                ans[i] = 0ll + s[0] + 1ll * n * (nums[0] - q);
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums, queries;
    nums = {47,50,97,58,87,72,41,63,41,51,17,21,7,100,69,66,79,92,84,9,57,26,26,28,83,38};
    queries = {3};
    for (int y : s.minOperations(nums, queries))
        std::cout << y << ' ';
    std::cout << std::endl;
    return 0;
}
