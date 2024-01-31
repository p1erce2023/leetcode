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

using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using UMPII = unordered_map<int,int>;
using VVVD = vector<vector<vector<double>>>;
using VVD = vector<vector<double>>;
using VD = vector<double>;
class Solution {
public:
    vector<pair<int,int>> dirs={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    double f(int r, int c, int k, int n, VVVD& mem) {
        if (k==0) return 1;
        if (mem[r][c][k] != -1) return mem[r][c][k];
        double ans=0;
        int nr, nc;
        for (auto [di, dj] : dirs) {
            nr=di+r, nc=dj+c;
            if (nr>=0 && nr<n && nc>=0 && nc<n)
                ans += 0.125 * f(nr, nc, k-1, n, mem);
        }
        return mem[r][c][k] = ans;
    }
    double knightProbability(int n, int k, int r, int c) {
        VVVD mem(n, VVD(n, VD(k+1, -1)));
        return f(r, c, k, n, mem);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n,k,row,column;
    n = 3, k = 2, row = 0, column = 0;
    OUT(sol.knightProbability(n,k,row,column));
    return 0;
}
