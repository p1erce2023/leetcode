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
    double f(int a, int b, vector<vector<pair<int, double>>>& e) {
        if (a == b) return 1;
        double ans;
        int n=e.size();
        vector<int> seen(n,0);
        vector<pair<int, double>> q={{a,1}};
        while (!q.empty()) {
            auto [t, v] = q.back();
            q.pop_back();
            seen[t] = 1;
            for (auto& [x, vv] : e[t]) {
                if (seen[x]) continue;
                if (x == b) return v * vv;
                seen[x] = 1;
                q.push_back({x, v*vv});
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> node_map;
        for (auto& vs : equations)
            for (auto& node : vs)
                if (!node_map.count(node))
                    node_map[node] = node_map.size();
        int n=node_map.size(), a, b;
        vector<vector<pair<int, double>>> e(n, vector<pair<int, double>>());
        for (int i=0; i<equations.size(); i++) {
            auto& ee = equations[i];
            a = node_map[ee[0]], b = node_map[ee[1]];
            e[a].push_back({b, values[i]});
            e[b].push_back({a, 1.0/values[i]});
        }
        vector<double> ans;
        for (auto& vq : queries) {
            if (node_map.count(vq[0]) && node_map.count(vq[1])) {
                a = node_map[vq[0]], b = node_map[vq[1]];
                ans.push_back(f(a,b,e));
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol.);
    return 0;
}
