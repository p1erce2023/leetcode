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
    int numSubseq(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, ans=0, MOD=1e9+7;
        sort(nums.begin(), nums.end());
        vector<int> vexp;
        bool ini = false;
        while (i<=j) {
            if (nums[i]+nums[j]>target) j--;
            else {
                if (!ini) {
                    ini = true;
                    vexp.resize(j-i+1);
                    vexp[0] = 1;
                    for (int k=1; k<vexp.size(); k++) {
                        vexp[k] = (2ll * vexp[k-1]) % MOD;
                    }
                }
                ans = (ans + vexp[j-i]) % MOD;
                i++;
            }
        }
        return ans;
    }
};

// [6 3 5 7]

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol.);
    return 0;
}
