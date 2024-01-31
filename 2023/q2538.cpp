#include <algorithm>
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
using ll = long long;

class Solution {
public:
    ll dfs1(int x, int p, vector<ll>& s, vector<ll>& s2, vector<vector<int>>& e, vector<int>& price) {
        ll ma=0,ma2=0,t;
        for (int y : e[x]) {
            if (y==p) continue;
            t = dfs1(y,x,s,s2,e,price) + price[y];
            if (t > ma) {ma2=ma,ma=t;}
            else if (t > ma2) {ma2=t;}
        }
        s[x] = ma, s2[x] = ma2;
        return ma;
    }

    void dfs2(ll& ans,int x, int p, vector<ll>& s, vector<ll>& s2, vector<vector<int>>& e, vector<int>& price) {
        int old_sx, old_sy, old_s2y, t;
        for (int y : e[x]) {
            if (y==p) continue;
            old_sx = s[x], old_sy = s[y], old_s2y = s2[y];
            if (s[x] == s[y]+price[y]) s[x] = s2[x];
            t = s[x]+price[x];
            if (t > s[y]) {s2[y]=s[y],s[y]=t;}
            else if (t > s2[y]) {s2[y]=t;}
            ans = max(ans,s[y]);
            dfs2(ans,y,x,s,s2,e,price);
            s[x] = old_sx, s[y] = old_sy, s2[y] = old_s2y;  // backtrack
        }
    }

    ll maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<ll> s(n,0), s2(n,0);
        vector<vector<int>> e(n, vector<int>());
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        // reroot 的思路一开始 TLE ，因为找次优用了再次查找
        // 后来改成维护最优和次优两个变量，又 WA 了一次
        // 因为在 reroot 时，除了最优会变，次优也会变，backtrack时又都要回溯
        dfs1(0,-1,s,s2,e,price);
        ll ans=s[0];
        dfs2(ans,0,-1,s,s2,e,price);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n;
    vector<vector<int>> edges;
    vector<int> price;
    n = 9;
    edges = {{1,7},{5,2},{2,3},{6,0},{0,4},{4,7},{7,3},{3,8}};
    price = {6,13,8,10,4,5,8,3,12};
    std::cout << sol.maxOutput(n,edges,price) << std::endl;
    n = 8;
    edges = {{1,7},{2,3},{4,0},{5,7},{6,3},{3,0},{0,7}};
    price = {4,5,6,2,2,7,7,8};
    std::cout << sol.maxOutput(n,edges,price) << std::endl;
    n = 6;
    edges = {{0,1},{1,2},{1,3},{3,4},{3,5}};
    price = {9,8,7,6,10,5};
    std::cout << sol.maxOutput(n,edges,price) << std::endl;
    n = 3;
    edges = {{0,1},{1,2}};
    price = {1,1,1};
    std::cout << sol.maxOutput(n,edges,price) << std::endl;
    return 0;
}
