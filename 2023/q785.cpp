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
using std::distance;
using std::lower_bound;
using std::upper_bound;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    bool dfs(int x, int y, vector<vector<int>>& graph, vector<int>& v) {
        v[x] = y;
        for (int nx : graph[x])
            if (v[nx] == -1) {
                if (!dfs(nx, 1-y, graph, v))
                    return false;
            } else if (v[nx] != 1-y)
                return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,-1);
        for (int i=0; i<n; i++) {
            if (graph[i].empty() || v[i] != -1) continue;
            if (!dfs(i, 0, graph, v)) return false;
        }
        return true;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> graph;
    graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    OUT(sol.isBipartite(graph));
    return 0;
}
