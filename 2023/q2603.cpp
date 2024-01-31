#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::priority_queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<unordered_set<int>> e(n, unordered_set<int>());
        for (auto& ee : edges) {
            e[ee[0]].insert(ee[1]);
            e[ee[1]].insert(ee[0]);
        }
        int t, nt;
        vector<int> leaf, nleaf;
        for (int i=0; i<n; i++) {
            t = i;
            while (e[t].size() == 1 && !coins[t]) {
                nt = *e[t].begin();
                e[nt].erase(t);
                e[t].erase(nt);
                t = nt;
            }
            if (e[t].size() == 1) leaf.push_back(t);
        }
        for (int j=0; j<2; j++) {
            for (int t : leaf) {
                if (e[t].empty()) continue;
                nt = *e[t].begin();
                e[nt].erase(t);
                e[t].erase(nt);
                if (e[nt].size() == 1) nleaf.push_back(nt);
            }
            // if (nleaf.empty()) break;
            leaf = std::move(nleaf);
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (!e[i].empty()) ans++;
        }
        return ans > 0? (ans - 1) * 2 : 0;
    }
};

int main() {
    auto s = Solution();
    vector<int> coins;
    vector<vector<int>> edges;
    coins = {1,0,0,0,0,1};
    edges = {{0,1},{1,2},{2,3},{3,4},{4,5}};
    std::cout << s.collectTheCoins(coins, edges) << std::endl;
    coins = {0,0,0,1,1,0,0,1};
    edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{5,6},{5,7}};
    std::cout << s.collectTheCoins(coins, edges) << std::endl;
    coins = {1, 1};
    edges = {{0,1}};
    std::cout << s.collectTheCoins(coins, edges) << std::endl;
    return 0;
}
