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
    void f(int s, vector<unordered_map<int,int>>& e, vector<LL>& d) {
        priority_queue<pair<LL,int>,vector<pair<LL,int>>,std::greater<>> pq;
        pq.push({0,s});
        LL ww;
        while (!pq.empty()) {
            auto [cw, x] = pq.top();
            pq.pop();
            if (d[x]!=-1 && d[x]<cw) continue;
            d[x] = cw;
            for (auto [y, w] : e[x]) {
                ww = cw + w;
                if (d[y] == -1 || ww < d[y]) {
                    d[y] = ww;
                    pq.push({ww,y});
                }
            }
        }
    }
    LL minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<unordered_map<int,int>> e(n), erev(n);
        vector<LL> d1(n,-1), d2(n,-1), dt(n,-1);
        for (auto& ee : edges) {
            if (e[ee[0]].count(ee[1]))
                e[ee[0]][ee[1]] = min(e[ee[0]][ee[1]], ee[2]);
            else 
                e[ee[0]][ee[1]] = ee[2];
            if (erev[ee[1]].count(ee[0]))
                erev[ee[1]][ee[0]] = min(erev[ee[1]][ee[0]], ee[2]);
            else
                erev[ee[1]][ee[0]] = ee[2];
        }
        f(src1, e, d1);
        f(src2, e, d2);
        f(dest, erev, dt);
        LL mi = 2e10+1;
        for (int i=0; i<n; ++i)
            if (d1[i] != -1 && d2[i] != -1 && dt[i] != -1)
                mi = min(mi, d1[i] + d2[i] + dt[i]);
        return mi==2e10+1? -1 : mi;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> edges;
    int n, src1, src2, dest;
    n = 6, edges = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}}, src1 = 0, src2 = 1, dest = 5;
    OUT(sol.minimumWeight(n,edges,src1,src2,dest));
    n = 3, edges = {{0,1,1},{2,1,1}}, src1 = 0, src2 = 1, dest = 2;
    OUT(sol.minimumWeight(n,edges,src1,src2,dest));
    n=5, edges={{4,2,20},{4,3,46},{0,1,15},{0,1,43},{0,1,32},{3,1,13}}, src1=0, src2=4, dest=1;
    OUT(sol.minimumWeight(n,edges,src1,src2,dest));
    return 0;
}
