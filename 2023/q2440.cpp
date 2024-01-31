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
    int dfs(int k, int x, int p, vector<vector<int>> &e, vector<int>& A) {
        int s=A[x], res;
        for (int nb : e[x]) {
            if (nb == p) continue;
            res = dfs(k, nb, x, e, A);
            if (res == -1) return -1;
            s += res;
            if (s > k) return -1;
        }
        return s % k;
    }
    int componentValue(vector<int>& A, vector<vector<int>>& edges) {
        int s=0, ma=0, n=A.size();
        vector<vector<int>> e(n, vector<int>());
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        for (int x : A) s+=x, ma=max(ma, x);
        for (int i=ma; i<=s/2; i++) {
            if (s % i) continue;
            if (dfs(i, 0, -1, e, A) == 0) return s/i-1;
        }
        return 0;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> nums; vector<vector<int>> edges;
    nums = {6,2,2,2,6}, edges = {{0,1},{1,2},{1,3},{3,4}};
    OUT(sol.componentValue(nums,edges));
    return 0;
}
