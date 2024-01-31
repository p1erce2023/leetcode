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
    int maximumRequests(int n, vector<vector<int>>& A) {
        int m=A.size(), c, ans=0;
        int v[21];
        for (int i=1; i<(1<<m); ++i) {
            memset(v,0,sizeof(v));
            c = 0;
            for (int j=0; j<m; ++j) {
                if (i & (1<<j))
                    --v[A[j][0]], ++v[A[j][1]], ++c;
            }
            bool achievable = true;
            for (int j=0; j<n; ++j)
                if (v[j] != 0) {
                    achievable = false;
                    break;
                }
            if (!achievable) continue;
            ans = max(ans, c);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> A; int n;
    n = 3, A = {{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}};
    OUT(sol.maximumRequests(n, A));
    return 0;
}

