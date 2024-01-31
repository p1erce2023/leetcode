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
// Standard Disjoint-set data structure implementation.
class DSU {
    vector<int> Parent, Rank;
    vector<unordered_set<int>> taken;
    int row, col;
public:
    DSU(int r, int c) {
        row=r, col=c;
        int n = r * c;
        Parent.resize(n, -1);
        Rank.resize(n, 0);
        taken.resize(n);
    }
    bool Flood(int i, int j) {
        int ci, cj, x=(i-1)*col+j-1, y;
        Parent[x] = x;
        taken[x].insert(j);
        for (int di=-1; di<2; ++di)
            for (int dj=-1; dj<2; ++dj) {
                if (!di && !dj) continue;
                ci=i+di, cj=j+dj;
                if (ci<1 || ci>row || cj<1 || cj>col) continue;
                y = (ci-1)*col+cj-1;
                if (Parent[y] == -1) continue;
                Union(x, y);
            }
        return taken[Find(x)].size()==col;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) return false;
        if (Rank[x] < Rank[y]) {
            Parent[x] = y;
            taken[y].insert(taken[x].begin(), taken[x].end());
            taken[x].clear();
        } else {
            Parent[y] = x;
            taken[x].insert(taken[y].begin(), taken[y].end());
            taken[y].clear();
        }
        Rank[x] += Rank[x] == Rank[y];
        return true;
    }
};
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        DSU dsu(row, col);
        for (int i=0; i<n; ++i)
            if (dsu.Flood(cells[i][0],cells[i][1]))
                return i;
        return 0;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int row, col;
    vector<vector<int>> cells;
    row = 6, col = 2, cells = {{4,2},{6,2},{2,1},{4,1},{6,1},{3,1},{2,2},{3,2},{1,1},{5,1},{5,2},{1,2}};
    OUT(sol.latestDayToCross(row,col,cells));
    return 0;
}
