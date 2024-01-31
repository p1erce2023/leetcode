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
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    vector<int> f(vector<int>& A, unordered_map<int, vector<int>>& g, unordered_map<int,int>& dg) {
        vector<int> ans, v, nv;
        for (int x : A) 
            if (dg[x] == 0)
                v.push_back(x);
        while (!v.empty()) {
            for (int x : v) {
                ans.push_back(x);
                for (int y : g[x]) {
                    dg[y]--;
                    if (dg[y] == 0)
                        nv.push_back(y);
                }
            }
            v = std::move(nv);
        }
        if (ans.size() == A.size())
            return ans;
        else return {};
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<unordered_map<int, vector<int>>> g(m+1);
        vector<unordered_map<int,int>> dg(m+1);
        int gi, gj, s, t;
        for (int i=0; i<beforeItems.size(); ++i) {
            gi = group[i];
            for (int j : beforeItems[i]) {
                gj = group[j];
                if (gi == gj) {
                    int x;
                    if (gi == -1) x = m;
                    else x = gi;
                    g[x][j].push_back(i);
                    dg[x][i]++;
                } else if (gi == -1) {
                    g[m][n+gj].push_back(i);
                    dg[m][i]++;
                } else if (gj == -1) {
                    g[m][j].push_back(n+gi);
                    dg[m][n+gi]++;
                } else {
                    g[m][n+gj].push_back(n+gi);
                    dg[m][n+gi]++;
                }
            }
        }
        vector<int> v, nv, ans;
        vector<vector<int>> vidx(m);
        for (int i=0; i<n; ++i) {
            if (group[i] != -1) {
                vidx[group[i]].push_back(i);
                continue;
            }
            if (dg[m][i]==0) v.push_back(i);
        }
        for (int j=0; j<m; ++j) {
            if (vidx[j].empty()) continue;
            if (dg[m][n+j] == 0) v.push_back(n+j);
        }
        while (!v.empty()) {
            for (int x : v) {
                if (x < n)
                    ans.push_back(x);
                else {
                    int gidx = x-n;
                    auto vv = f(vidx[gidx], g[gidx], dg[gidx]);
                    if (vv.empty()) return {};
                    for (int yy : vv)
                        ans.push_back(yy);
                }
                for (int y : g[m][x]) {
                    dg[m][y]--;
                    if (dg[m][y] == 0)
                        nv.push_back(y);
                }
            }
            v = std::move(nv);
        }
        if (ans.size() == n)
            return ans;
        else
            return {};
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n, m; VI group; VVI beforeItems;
    n = 8, m = 2, group = {-1,-1,1,0,0,1,0,-1}, beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
    for (auto vi : sol.sortItems(n,m,group,beforeItems)) { std::cout << vi << ' '; }
    std::cout << std::endl;

    n = 8, m = 2, group = {-1,-1,1,0,0,1,0,-1}, beforeItems = {{},{6},{5},{6},{3},{},{4},{}};
    for (auto vi : sol.sortItems(n,m,group,beforeItems)) { std::cout << vi << ' '; }
    std::cout << std::endl;

    return 0;
}
