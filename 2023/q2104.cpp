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
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

// medium 题加大数据量，直接逼出 O(n) 解法，mono stack 难搞啊
// 一开始没想明白，mono stack 变化时，如何O(1)维护状态变化，思维殿堂了
// 明明就是差值的变化，不知道当时怎么想到乘法上去了
class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
        vector<pair<LL, int>> lg, sm;  // mono stack
        LL ans=0, cur=0;
        int x;
        for (int a : A) {
            x=1;
            while (!lg.empty() && a > lg.back().first) {
                x += lg.back().second;
                cur += (a - lg.back().first) * lg.back().second;
                lg.pop_back();
            }
            if (lg.empty() || a < lg.back().first) {
                lg.push_back({a, x});
            } else {
                lg.back().second++;
            }
            x=1;
            while (!sm.empty() && a < sm.back().first) {
                x += sm.back().second;
                cur += (sm.back().first - a) * sm.back().second;
                sm.pop_back();
            }
            if (sm.empty() || a > sm.back().first) {
                sm.push_back({a, x});
            } else {
                sm.back().second++;
            }
            ans += cur;
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI A;
    A = {1,2,3};
    OUT(sol.subArrayRanges(A));
    return 0;
}
