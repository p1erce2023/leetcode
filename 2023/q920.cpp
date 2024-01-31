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
using std::accumulate;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;

class Solution {
public:
    int f(int x, int y, int d, int n) {
        int ans;
        if (d==n) ans = 0;
        else ans = (1ll * f(x, y, d+1, n) * (n-d)) % MOD;
        if (x != y)
            ans = (ans + 1ll * f(x+1, y, d, n) * d) % MOD; 
        return ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        // k+1个distinct, goal-k-1里，n-k-1个distinct，goal-n个随意
        int ans=1, MOD=1e9+7;
        for (int i=0; i<k+1; ++i)
            ans = (ans * (n-i)) % MOD;
        f(0, goal-n, k+1, n)
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
