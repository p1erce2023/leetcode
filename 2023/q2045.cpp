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
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int T, int duration) {
        vector<vector<int>> e(n+1);
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        vector<int> d1(n+1,1e5), d2(n+1, 1e5), v={1}, nv;
        int d=0;
        d1[1] = d++;
        while (!v.empty()) {
            for (int x : v) {
                for (int y : e[x]) {
                    if (d > d1[y]) continue;
                    d1[y] = d;
                    nv.push_back(y);
                }
            }
            v = std::move(nv);
            ++d;
            if (d > d1[n]) break;
        }
        v = {n}, d=1, d2[n] = 0;
        while (!v.empty()) {
            for (int x : v) {
                for (int y : e[x]) {
                    if (d > d2[y]) continue;
                    d2[y] = d;
                    nv.push_back(y);
                }
            }
            v = std::move(nv);
            ++d;
            if (d > d2[1]) break;
        }
        int mi=d1[n];
        bool found = false;
        for (int i=1; i<=n; ++i) {
            if (d1[i] > mi || d2[i] > mi) continue;
            for (int j : e[i]) {
                if (d1[i] + d2[j] == mi) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        int x = mi + 2, ans = 0;
        if (found) --x;
        while (x--) {
            ans += T;
            if (int(ans/duration) % 2 && x)
                ans = (int(ans/duration)+1) * duration;
        }
        return ans;
    }
};

int main() {
    // int x=11, ans=0, T=861, duration=272;
    // while (x--) {
    //     ans += T;
    //     if (int(ans/duration) % 2 && x)
    //         ans = (int(ans/duration)+1) * duration;
    // }
    // cout << ans << '\n';
    auto sol = Solution();
    // parameters init
    int n, time, change; VVI edges;
    n = 2, edges = {{1,2}}, time = 3, change = 2;
    OUT(sol.secondMinimum(n,edges,time,change));
    return 0;
}
