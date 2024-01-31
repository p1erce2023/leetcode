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
using std::distance;
using std::lower_bound;
using std::upper_bound;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> b(32);
        int i;
        for (unsigned x : nums) {
            i = 0;
            while (x != 0) {
                if (x&1) b[i] = (b[i]+1) % 3;
                i++;
                x = x>>1;
            }
        }
        i=0;
        for (int j=0; j<32; j++)
            if (b[j]) i |= 1<<j;
        return i;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums;
    nums = {2,2,3,2};
    OUT(sol.singleNumber(nums));
    nums = {0,1,0,1,0,1,99};
    OUT(sol.singleNumber(nums));
    nums = {-99,0,1,0,1,0,1};
    OUT(sol.singleNumber(nums));
    return 0;
}
