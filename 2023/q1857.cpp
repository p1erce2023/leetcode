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
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // topological sort 还是用了 indegree 那一套
        // dfs 那套不写成递归的形式，感觉很不好搞啊，网上搜、自己实现都没搞定
        int n = colors.size(), seen = 0, ans = 0;
        vector<vector<int>> e(n), dp(n, vector<int>(26,0));
        vector<int> outdegree(n, 0), q, nq;
        for (auto& ee : edges) {
            outdegree[ee[0]]++;
            e[ee[1]].push_back(ee[0]);
        }
        for (int i=0; i<n; i++) {
            if (outdegree[i] == 0) {
                q.push_back(i);
                dp[i][colors[i]-'a']++;
            }
        }
        while (!q.empty()) {
            seen += q.size();
            for (int x : q) {
                for (int f : e[x]) {
                    for (int i=0; i<26; i++) {
                        if (i == colors[f]-'a')
                            dp[f][i] = max(dp[f][i], dp[x][i] + 1);
                        else
                            dp[f][i] = max(dp[f][i], dp[x][i]);
                    }
                    outdegree[f]--;
                    if (outdegree[f] == 0) nq.push_back(f);
                }
                if (e[x].empty()) {
                    ans = max(ans, *std::max_element(dp[x].begin(), dp[x].end()));
                }
            }
            q = std::move(nq);
        }
        return seen == n? ans : -1;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string colors; vector<vector<int>> edges;
    colors = "abaca", edges = {{0,1},{0,2},{2,3},{3,4}};
    std::cout << sol.largestPathValue(colors, edges) << std::endl;
    colors = "a", edges = {{0,0}};
    std::cout << sol.largestPathValue(colors, edges) << std::endl;
    colors = "iivvvvv", edges = {{0,1},{1,2},{1,3},{2,3},{3,4},{2,4},{3,5},{1,5},{4,5},{5,6}};
    std::cout << sol.largestPathValue(colors, edges) << std::endl;
    return 0;
}
