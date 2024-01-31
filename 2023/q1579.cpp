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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

// Standard Disjoint-set data structure implementation.
class DSU {
public:
    vector<int> Parent, Rank;
    DSU(DSU& d) {
        Parent = d.Parent, Rank = d.Rank;
    }
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 1);
        for (int i=0; i<n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) return false;
        if (Rank[x] < Rank[y]) Rank[y] += Rank[x], Parent[x] = y;
        else Rank[x] += Rank[y], Parent[y] = x;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU d1(n+1);
        int added, ans=0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                added = d1.Union(e[1], e[2]);
                if (!added) ans++;
            }
        }
        DSU d2(d1);
        for (auto& e : edges) {
            if (e[0] == 1) {
                added = d1.Union(e[1], e[2]);
                if (!added) ans++;
            } else if (e[0] == 2) {
                added = d2.Union(e[1], e[2]);
                if (!added) ans++;
            }
        }
        if (d1.Rank[d1.Find(1)] != n || d2.Rank[d2.Find(1)] != n)
            return -1;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n; vector<vector<int>> edges;
    n = 4, edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    OUT(sol.maxNumEdgesToRemove(n,edges));
    n = 4, edges = {{3,1,2},{3,2,3},{1,1,4},{2,1,4}};
    OUT(sol.maxNumEdgesToRemove(n,edges));
    n = 4, edges = {{3,2,3},{1,1,2},{2,3,4}};
    OUT(sol.maxNumEdgesToRemove(n,edges));
    return 0;
}
