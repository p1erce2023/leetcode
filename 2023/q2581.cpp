#include <vector>
#include <unordered_set>
#include <utility>
#include <iostream>
using std::vector;
using std::pair;
using std::unordered_set;


class Solution {
public:
    int64_t myhash(int32_t a, int32_t b) {
        int64_t c = a;
        c = c << 32;
        c |= b;
        return c;
    };

    int rootCount2(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        size_t n = edges.size() + 1;
        int ans = 0, s, t;
        vector<vector<int> > adj(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int64_t> guess;
        for (auto& g : guesses) {
            guess.insert(myhash(static_cast<int32_t>(g[0]), static_cast<int32_t>(g[1])));
        }
        vector<int> q;
        unordered_set<int> ancestors;
        for (int root = 0; root < static_cast<int>(n); root++) {
            s = 0;
            // traverse tree
            q = {root};
            ancestors = {root};
            bool early_exit = false;
            while (!q.empty()) {
                t = q.back();
                q.pop_back();
                for (int x : adj[t]) {
                    if (ancestors.find(x) != ancestors.end()) continue;
                    if (guess.find(myhash(t, x)) != guess.end()) {
                        s++;
                        if (s >= k) {
                            ans++;
                            early_exit = true;
                            break;
                        }
                    }
                    q.push_back(x);
                    ancestors.insert(x);
                }
                if (early_exit) break;
            }
        }
        return ans;
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        size_t n = edges.size() + 1;
        int ans = 0, c = 0, t;
        vector<vector<int> > adj(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int64_t> guess;
        for (auto& g : guesses) {
            guess.insert(myhash(static_cast<int32_t>(g[0]), static_cast<int32_t>(g[1])));
        }
        vector<int> q = {0};
        unordered_set<int> ancestors = {0};
        while (!q.empty()) {
            t = q.back();
            q.pop_back();
            for (int x : adj[t]) {
                if (ancestors.find(x) != ancestors.end()) continue;
                q.push_back(x);
                auto p = myhash(t, x);
                if (guess.find(p) != guess.end()) c++;
                ancestors.insert(x);
            }
        }
        if (c >= k) ans++;
        // root 0 tree, there's c right in guess
        vector<pair<int, int>> q2 = {{0, c}};
        ancestors = {0};
        int cc;
        while (!q2.empty()) {
            auto top = q2.back();
            std::tie(t, c) = top;
            q2.pop_back();
            for (int x : adj[t]) {
                if (ancestors.find(x) != ancestors.end()) continue;
                // change to root x tree, edge pairs change only one
                auto _old_edge = myhash(t, x);
                auto _new_edge = myhash(x, t);
                cc = c;
                if (guess.find(_old_edge) != guess.end()) cc--;
                if (guess.find(_new_edge) != guess.end()) cc++;
                if (cc >= k) ans++;
                q2.push_back({x, cc});
                ancestors.insert(x);
            }
        }
        return ans;
    }
};


int main() {
    auto s = Solution();
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}}, guesses = {{1,0},{3,4},{2,1},{3,2}};
    int k = 1;
    std::cout << s.rootCount2(edges, guesses, k) << ' ' << s.rootCount(edges, guesses, k) << std::endl;
    return 0;
}