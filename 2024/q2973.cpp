#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VVI = vector<vector<int>>;
using LL = long long;
using VI = vector<int>;
class Solution {
public:
    pair<vector<int>, vector<int>> f(int x, int p, vector<LL>& coin, vector<vector<int>>& e, const vector<int>& cost) {
        priority_queue<int, vector<int>, greater<>> neg_pq, pos_pq;
        if (cost[x] > 0) pos_pq.push(cost[x]);
        else neg_pq.push(-cost[x]);
        for (int y : e[x]) {
            if (y == p) continue;
            auto [child_neg, child_pos] = f(y, x, coin, e, cost);
            for (int val : child_neg) {
                if (neg_pq.size() < 3)
                    neg_pq.push(val);
                else if (val > neg_pq.top()) {
                    neg_pq.pop();
                    neg_pq.push(val);
                }
            }
            for (int val : child_pos) {
                if (pos_pq.size() < 3)
                    pos_pq.push(val);
                else if (val > pos_pq.top()) {
                    pos_pq.pop();
                    pos_pq.push(val);
                }
            }
        }
        vector<int> pos, neg;
        while (!pos_pq.empty()) {
            pos.push_back(pos_pq.top());
            pos_pq.pop();
        }
        while (!neg_pq.empty()) {
            neg.push_back(neg_pq.top());
            neg_pq.pop();
        }
        int nn = neg.size(), np = pos.size();
        if (np + nn >= 3) {
            if (nn >= 2) {
                if (np > 0) {
                    if (np >= 3) {
                        // max(neg1 * neg2 * pos1, pos1 * pos2 * pos3)
                        LL ans1 = 1ll * neg[nn-1] * neg[nn-2] * pos[np-1];
                        LL ans2 = 1ll * pos[np-1] * pos[np-2] * pos[np-3];
                        coin[x] = max(ans1, ans2);
                    } else {
                        // neg1 * neg2 * pos1
                        coin[x] = 1ll * neg[nn-1] * neg[nn-2] * pos[np-1];
                    }
                } else {
                    coin[x] = 0;
                }
            } else if (nn == 1 && np == 2) {
                coin[x] = 0;
            } else { // no neg
                coin[x] = 1ll * pos[np-1] * pos[np-2] * pos[np-3];
            }
        } else {
            coin[x] = 1;
        }
        return {neg, pos};
    }
    vector<LL> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=cost.size();
        vector<vector<int>> e(n);
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        vector<LL> coin(n);
        f(0, -1, coin, e, cost);
        return coin;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
}

/*
思路很快很直接，保留正数最大的3个以及负数最小（绝对值最大）的2个，dfs递归
但是写的又慢又臭又长
*/