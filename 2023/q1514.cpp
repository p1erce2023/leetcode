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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>> pq;
        vector<vector<pair<int,double>>> e(n, vector<pair<int,double>>());
        for (int i=0; i<edges.size(); i++) {
            auto& ee = edges[i];
            e[ee[0]].push_back({ee[1], succProb[i]});
            e[ee[1]].push_back({ee[0], succProb[i]});
        }
        vector<int> black(n,0);
        pq.push({0,start});
        double lp; int t;
        while (!pq.empty()) {
            std::tie(lp,t) = pq.top();
            pq.pop();
            if (black[t]) continue;
            black[t] = 1;
            if (t == end) return std::exp(lp);
            for (auto [k, sp] : e[t]) {
                if (black[k]) continue;
                pq.push({std::log(sp)+lp, k});
            }
        }
        return 0;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n, start, end;
    vector<vector<int>> edges; vector<double> succProb;
    n = 3, edges = {{0,1},{1,2},{0,2}}, succProb = {0.5,0.5,0.2}, start = 0, end = 2;
    std::cout << sol.maxProbability(n,edges,succProb,start,end) << std::endl;
    n = 3, edges = {{0,1},{1,2},{0,2}}, succProb = {0.5,0.5,0.3}, start = 0, end = 2;
    std::cout << sol.maxProbability(n,edges,succProb,start,end) << std::endl;
    n = 3, edges = {{0,1}}, succProb = {0.5}, start = 0, end = 2;
    std::cout << sol.maxProbability(n,edges,succProb,start,end) << std::endl;
    return 0;
}
