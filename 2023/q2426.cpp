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

class NumArray {
    vector<int> ss;
    int n;
public:
    NumArray(int x) {
        ss.resize(x+1,0);
        n = x;
    }

    void update(int index) {
        for (int i=index+1; i<=n; i+=(i&-i))
            ss[i] += 1;
    }

    int count(int right) {
        int s=0;
        for (int i=right+1; i; i-=(i&-i)) s += ss[i];
        return s;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& A, vector<int>& B, int diff) {
        int n=A.size(), x;
        for (int i=0; i<n; i++) A[i] -= B[i];
        vector<int> v(n), d(n);
        std::iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int a, int b) {
            return A[a] < A[b];
        });
        for (int i=0; i<n; i++) d[v[i]] = i;
        NumArray t(n);
        long long ans=0;
        t.update(d[n-1]);
        for (int j=n-2; j>=0; --j) {
            x = lower_bound(v.begin(), v.end(), A[j] - diff, [&](auto& p, int v) {
                return A[p] < v;
            }) - v.begin();
            ans += n-1-j-t.count(x-1);
            t.update(d[j]);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums1, nums2; int diff;
    nums1 = {3,2,5}, nums2 = {2,2,1}, diff = 1;
    OUT(sol.numberOfPairs(nums1, nums2, diff));
    nums1 = {3,-1}, nums2 = {-2,2}, diff = -1;
    OUT(sol.numberOfPairs(nums1, nums2, diff));
    return 0;
}
