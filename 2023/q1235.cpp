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
using std::multiset;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::max;
using std::min;
using std::next;
using std::distance;
using std::accumulate;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    int jobScheduling(vector<int>& S, vector<int>& T, vector<int>& P) {
        int n=S.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return T[a] < T[b];
        });
        int s,t,p;
        map<int,int> dp;
        for (int i : idx) {
            s=S[i], t=T[i], p=P[i];
            if (!dp.count(t)) {
                if (dp.empty())
                    dp[t] = 0;
                else
                    dp.emplace(t, next(dp.end(), -1)->second);
            }
            auto it = dp.upper_bound(s);
            if (it == dp.begin())
                dp[t] = max(dp[t], p);
            else
                dp[t] = max(dp[t], next(it, -1)->second + p);
        }
        return next(dp.end(), -1)->second;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI S,T,P;
    S = {1,2,3,3}, T = {3,4,5,6}, P = {50,10,40,70};
    OUT(sol.jobScheduling(S,T,P));
    return 0;
}
