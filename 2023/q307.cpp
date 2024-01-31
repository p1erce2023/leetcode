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

class NumArray {
    vector<int> v, ss;  // original, BIT
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        v.resize(n,0);
        ss.resize(n+1,0);
        for (int i=0; i<n; i++) update(i,nums[i]);
    }

    void update(int index, int val) {
        int d = val-v[index];
        v[index] = val;
        for (int i=index+1; i<=n; i += (i&-i)) ss[i] += d;
    }

    int sumRange(int left, int right) {
        int s=0;
        for (int i=right+1; i; i-=(i&-i)) s+=ss[i];
        for (int i=left; i; i-=(i&-i)) s-=ss[i];
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    // parameters init
    vector<int> nums;
    nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    OUT(obj->sumRange(0, 2)); // return 1 + 3 + 5 = 9
    obj->update(1, 2);   // nums = [1, 2, 5]
    OUT(obj->sumRange(0, 2)); // return 1 + 2 + 5 = 8
    return 0;
}
