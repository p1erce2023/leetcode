#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    inline pair<int, int> getRange(int n, int pivot, int k) {
		// Left most subarray containing pivot
        int l1 = max(0, pivot - k + 1);
        int r1 = l1 + k - 1;

		// Right most subarray containing pivot
        int r2 = min(n - 1, pivot + k - 1);
        int l2 = r2 - k + 1;

		int left = r1 - (pivot - l1);
        int right = l2 + (r2 - pivot);
        return {left, right};
    }

    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        ans[p] = 0;
        vector<set<int>> s(2);
        for (int i=0; i<n; i++) s[i & 1].insert(i);
        for (int x : banned) s[x & 1].erase(x);
        s[p & 1].erase(p);
        queue<int> q;
        q.push(p);
        int t, d, left, right, o;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            std::tie(left, right) = getRange(n, t, k);
            o = k & 1? t&1 : (1 - t&1);
            auto bg = s[o].lower_bound(left), ed = s[o].upper_bound(right);
            for (auto it=bg; it!=ed; it++) {
                ans[*it] = ans[t]+1;
                q.push(*it);
            }
            s[o].erase(bg, ed);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n, p, k; vector<int> banned;
    n=4, p=0, k=4, banned={1,2};
    for (int x : sol.minReverseOperations(n,p,banned,k)) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    n=4, p=0, k=4, banned={};
    for (int x : sol.minReverseOperations(n,p,banned,k)) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    n=5, p=0, k=3, banned={2,4};
    for (int x : sol.minReverseOperations(n,p,banned,k)) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    n=4, p=2, k=1, banned={0,1,3};
    for (int x : sol.minReverseOperations(n,p,banned,k)) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    n=2, p=1, k=2, banned={};
    for (int x : sol.minReverseOperations(n,p,banned,k)) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    return 0;
}

