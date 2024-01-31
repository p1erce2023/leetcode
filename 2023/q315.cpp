#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::array;
using std::deque;
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
using std::next;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    int get_sum(vector<int>& bit, int x) {
        int s=0;
        for (int i=x+1; i; i-=i&-i) s+=bit[i];
        return s;
    }
    void update(vector<int>& bit, int x) {
        for (int i=x+1; i<bit.size(); i+=i&-i) bit[i]++;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size(), x;
        vector<int> bit(2e4+2), ans(n);  // 数组直接开到最大，20002是对的
        // 很多题解写的20001，少更新一个，但也问题不大，因为 get_sum 最多只到20000
        for (int i=n-1; i>-1; i--) {
            x = nums[i] + 1e4;
            ans[i] = get_sum(bit, x-1);
            update(bit, x);
        }
        return ans;
    }
};

class Solution2 {
public:
    int get_sum(vector<int>& bit, int x) {
        int s=0;
        for (int i=x+1; i; i-=i&-i) s+=bit[i];
        return s;
    }
    void update(vector<int>& bit, int x) {
        for (int i=x+1; i<bit.size(); i+=i&-i) bit[i]++;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size(), x;
        vector<int> bit(n+1), ans(n), arr(nums);  // 数组按n来开，离散化，如果 nums[i] 的范围是 [-1e8,1e8]
        sort(arr.begin(), arr.end());
        for (int i=n-1; i>-1; i--) {
            x = std::distance(arr.begin(), std::upper_bound(arr.begin(), arr.end(), nums[i]-1));
            ans[i] = get_sum(bit, x);
            x = std::distance(arr.begin(), std::upper_bound(arr.begin(), arr.end(), nums[i])) - 1;
            update(bit, x);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    auto sol2 = Solution2();
    // parameters init
    vector<int> nums;
    nums = {5,2,6,1};
    for (auto vi : sol.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : sol2.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    nums = {5,2,6,1,3};
    for (auto vi : sol.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : sol2.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    nums = {-1};
    for (auto vi : sol.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : sol2.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    nums = {-1,-1};
    for (auto vi : sol.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : sol2.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    nums = {3};
    for (auto vi : sol.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : sol2.countSmaller(nums)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
