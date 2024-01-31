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
using std::multiset;
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
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using LL = long long;
class Solution {
public:
    bool find132pattern(vector<int>& A) {  // O(n)
        int n=A.size(), mi=1e9;
        vector<int> vmin(n), stack;
        for (int i=0; i<n; ++i) {
            mi = min(mi, A[i]);
            vmin[i] = mi;
        }
        for (int i=n-1; i>=0; --i) {
            while (!stack.empty() && stack.back() <= vmin[i])
                stack.pop_back();
            if (stack.empty())
                stack.push_back(A[i]);
            else if (stack.back() < A[i])
                return true;
            else
                stack.push_back(A[i]);
        }
        return false;
    }

    bool find132pattern2(vector<int>& A) {  // O(nlogn)
        int mi=A[0], n=A.size();
        map<int,int> mp;
        for (int i=1; i<n; ++i) {
            if (A[i] <= mi)
                mi = A[i];
            else {
                auto it = mp.upper_bound(A[i]);
                if (it==mp.begin()) {
                    if (mi != A[i])
                        mp[mi] = A[i];
                } else {
                    it = next(it,-1);
                    if (it->second > A[i] && A[i] > it->first)
                        return true;
                    int x = max(it->second, A[i]);
                    auto jt=mp.lower_bound(mi);
                    mp.erase(jt, next(it,1));
                    mp[mi] = x;
                }
            }
        }
        return false;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums;
    nums = {2,1,3};
    OUT(sol.find132pattern(nums));
    nums = {14,19,4,8,16};
    OUT(sol.find132pattern(nums));
    nums = {1,2,3,4};
    OUT(sol.find132pattern(nums));
    nums = {3,1,4,2};
    OUT(sol.find132pattern(nums));
    nums = {-1,3,2,0};
    OUT(sol.find132pattern(nums));
    return 0;
}
