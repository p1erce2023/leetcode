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
    long long minimumCost(vector<int>& v, int k, int d) {
        map<int, int> cost, other;
        int n=v.size(), cost_sz=0;
        LL cur_cost_sum=0;
        --k;
        for (int i=1; i<=d+1; ++i) {
            if (cost_sz < k) {
                ++cost_sz;
                cur_cost_sum += v[i];
                cost[v[i]]++;
            } else {
                int cost_max = cost.rbegin()->first;
                if (v[i] >= cost_max) {
                    other[v[i]]++;
                } else {
                    cost[cost_max]--;
                    if (cost[cost_max] == 0) cost.erase(cost_max);
                    other[cost_max]++;
                    cost[v[i]]++;
                    cur_cost_sum += v[i] - cost_max;
                }
            }
        }
        LL mi = cur_cost_sum;
        // slide window
        for (int i=d+2, j; i<n; ++i) {
            j = i-d-1;
            if (v[i] == v[j]) continue;
            // remove v[j]
            if (other.count(v[j])) {
                other[v[j]]--;
                if (other[v[j]] == 0) other.erase(v[j]);
            } else {
                cost[v[j]]--;
                if (cost[v[j]] == 0) cost.erase(v[j]);
                cur_cost_sum -= v[j];
                --cost_sz;
                if (!other.empty()) {
                    ++cost_sz;
                    int other_mi = other.begin()->first;
                    cost[other_mi]++;
                    cur_cost_sum += other_mi;
                    other[other_mi]--;
                    if (other[other_mi] == 0) other.erase(other_mi);
                }
            }
            // add v[i]
            if (cost_sz < k) {
                ++cost_sz;
                cur_cost_sum += v[i];
                cost[v[i]]++;
            } else {
                int cost_max = cost.rbegin()->first;
                if (v[i] >= cost_max) {
                    other[v[i]]++;
                } else {
                    cost[cost_max]--;
                    if (cost[cost_max] == 0) cost.erase(cost_max);
                    other[cost_max]++;
                    cost[v[i]]++;
                    cur_cost_sum += v[i] - cost_max;
                }
            }
            mi = min(mi, cur_cost_sum);
        }
        return mi + v[0];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI nums; int k, dist;
    nums = {10,8,18,9}, k = 3, dist = 1;
    OUT(sol.minimumCost(nums, k, dist));
}

/*
不难，slide window + 区间k个最小值的和，用了2个map实现，固定一个size=k
这就只有300人AC了？！
*/