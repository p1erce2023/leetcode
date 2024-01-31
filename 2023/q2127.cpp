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
    int bfs(int x, int p, const vector<vector<int>>& e, vector<int>& v) {
        if (e[x].size() == 1) return 1;
        v[x] = 1;
        vector<int> vv, nv;
        for (int t : e[x])
            if (t != p) {
                vv.push_back(t);
                v[t] = 2;
            }
        int d = 2, ans = 0;
        while (!vv.empty()) {
            for (int y : vv) {
                if (e[y].empty()) 
                    ans = d;
                for (int t : e[y]) {
                    if (t == p || v[t] != -1) continue;
                    v[t] = d + 1;
                    nv.push_back(t);
                }
            }
            ++d;
            vv = std::move(nv);
        }
        return ans;
    }
    int maximumInvitations(vector<int>& F) {
        int n=F.size(), ans=0;
        vector<int> v(n, -1);
        vector<vector<int>> e(n);
        for (int i=0; i<n; ++i)
            e[F[i]].push_back(i);
        for (int i=0; i<n; ++i) {
            if (F[i] > i &&  F[F[i]] == i) {
                int d1 = bfs(i, F[i], e, v);
                int d2 = bfs(F[i], i, e, v);
                ans += d1+d2;
            }
        }
        for (int i=0; i<n; ++i) {
            if (v[i] != -1) continue;
            int la=i, d=0, j=i;
            vector<int> path;
            while (v[j] == -1) {
                v[j] = d++;
                la = j;
                path.push_back(j);
                j = F[j];
            }
            ans = max(ans, v[la]-v[j]+1);
            for (int xx : path)
                bfs(F[xx], xx, e, v);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI F;
    // F = {2,2,1,2};
    // OUT(sol.maximumInvitations(F));
    // F = {1,2,0};
    // OUT(sol.maximumInvitations(F));
    // F = {3,0,1,4,1};
    // OUT(sol.maximumInvitations(F));
    F = {1,0,3,2,5,6,7,4,9,8,11,10,11,12,10};
    OUT(sol.maximumInvitations(F));
    return 0;
}
