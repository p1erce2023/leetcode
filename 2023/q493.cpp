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
    int f(int s, int t, vector<int>& nums) {
        if (s+1 == t) return 0;
        int mid=(s+t)/2, i=s, j=mid, k, ans;
        ans = f(s,mid,nums) + f(mid,t,nums);
        while (i<mid && j<t) {
            while (i<mid && nums[i] <= 2*nums[j]) i++;
            ans += mid-i;
            j++;
        }
        i=s,j=mid,k=0;
        vector<int> arr(t-s);
        while (i<mid && j<t) {
            if (nums[i] <= nums[j]) {
                arr[k++] = nums[i++];
            } else {
                arr[k++] = nums[j++];
            }
        }
        while (i<mid) arr[k++] = nums[i++];
        while (j<t) arr[k++] = nums[j++];
        for (int i=0; i<t-s; i++) nums[s+i] = arr[i];
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size(), mid=n/2;
        return f(0, n, nums);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums;
    nums = {1,3,2,3,1};
    OUT(sol.reversePairs(nums));
    nums = {2,4,3,5,1};
    OUT(sol.reversePairs(nums));
    return 0;
}
