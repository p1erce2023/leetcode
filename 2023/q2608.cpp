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

class Solution {
public:
    int _MAX = 1001;

    int bfs(int x, vector<vector<int>>& e, vector<int>& ss) {
        if (ss[x]) return _MAX;
        int n = e.size(), ans = _MAX;
        vector<int> s(n, -1);
        s[x] = 0;
        vector<pair<int, int>> q, nq;
        q.push_back({x, -1});
        while (!q.empty()) {
            for (auto [t, _from] : q) {
                for (int y : e[t]) {
                    if (y == _from) continue;
                    if (s[y] != -1) {
                        ans = min(ans, s[y] + s[t] + 1);
                    } else {
                        s[y] = s[t]+1;
                        nq.push_back({y,t});
                    }
                }
            }
            if (ans != _MAX) break;
            q = std::move(nq);
        }
        if (ans == _MAX) {
            for (int i=0; i<n; i++) if (s[i] != -1) ss[i] = 1;
        }
        return ans;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n, vector<int>());
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        int ans = _MAX;
        vector<int> ss(n, 0);
        for (int i=0; i<n; i++) {
            ans = min(ans, bfs(i, e, ss));
        }
        if (ans == _MAX) ans = -1;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n; vector<vector<int>> edges;
    // 这个错例告诉我们，必须等到一层结束
    n = 6, edges = {{4,2},{5,1},{5,0},{0,3},{5,2},{1,4},{1,3},{3,4}};
    std::cout << sol.findShortestCycle(n, edges) << std::endl;
    n = 4, edges = {{0,1},{0,2}};
    std::cout << sol.findShortestCycle(n, edges) << std::endl;
    return 0;
}
