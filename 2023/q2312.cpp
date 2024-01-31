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
using VVI = vector<vector<int>>;
using VI = vector<int>;
class Solution {
public:
    LL f(int m, int n, VVI& w, VVI& mem) {
        if (mem[m][n] != -1) return mem[m][n];
        LL ans=0;
        if (w[m][n]) ans = w[m][n];
        for (int i=1; i<=m/2; ++i)
            ans = max(ans, f(i,n,w,mem) + f(m-i,n,w,mem));
        for (int j=1; j<=n/2; ++j)
            ans = max(ans, f(m,j,w,mem) + f(m,n-j,w,mem));
        return mem[m][n] = ans;
    }
    LL sellingWood(int m, int n, VVI& P) {
        VVI mem(m+1, VI(n+1, -1)), w(m+1, VI(n+1, 0));
        for (auto& v : P)
            w[v[0]][v[1]] = v[2];
        return f(m, n, w, mem);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int m,n; VVI prices;
    m = 3, n = 5, prices = {{1,4,2},{2,2,7},{2,1,3}};
    OUT(sol.sellingWood(m,n,prices));
    m = 4, n = 6, prices = {{3,2,10},{1,4,2},{4,1,3}};
    OUT(sol.sellingWood(m,n,prices));
    return 0;
}
