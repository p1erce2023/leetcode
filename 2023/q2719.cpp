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
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;

class Solution {
public:
    int MOD=1e9+7;
    int dp[22+1][22*9+1][2];
    int f2(int x, int idx, bool sm, string& s, int mi, int ma) {
        if (x > ma) return 0;
        if (idx == s.size())
            return mi<=x && x<= ma;
        if (dp[idx][x][sm] != -1) 
            return dp[idx][x][sm];
        int ans=0;
        if (sm) {
            for (int j=0; j<=9; ++j)
                ans = (ans + f2(x+j, idx+1, true, s, mi, ma)) % MOD;
        } else {
            for (int j=0; j<=s[idx]-'0'; ++j)
                ans = (ans + f2(x+j, idx+1, j<s[idx]-'0', s, mi, ma)) % MOD;
        }
        return dp[idx][x][sm] = ans;
    }
    int f(string& s, int mi, int ma) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i=1; i<s.size(); ++i)
            for (int j=1; j<=9; ++j)
                ans = (ans + f2(j, i+1, true, s, mi, ma)) % MOD;
        for (int j=1; j<=s[0]-'0'; ++j)
            ans = (ans + f2(j, 1, j<s[0]-'0', s, mi, ma));  // 这里漏写一个取模
        return ans;
    }
    bool ds(string& s, int mi, int ma) {
        int x=0;
        for (char c : s) x += c-'0';
        return mi<=x && x<=ma;
    }
    int count(string a, string b, int mi, int ma) {
        return f(b, mi, ma) - f(a, mi, ma) + (ds(a, mi, ma)? 1 : 0);  // 这里，又是取模减法得负
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string num1, num2; int min_sum, max_sum;
    num1 = "1", num2 = "12", min_sum = 1, max_sum = 8;
    OUT(sol.count(num1, num2, min_sum, max_sum));
    num1 = "1", num2 = "5", min_sum = 1, max_sum = 5;
    OUT(sol.count(num1, num2, min_sum, max_sum));
    num1 = "77", num2 = "2555", min_sum = 16, max_sum = 23;
    OUT(sol.count(num1, num2, min_sum, max_sum));
    int ans=0;
    string s;
    for (int i=77; i<=2555; ++i) {
        s = std::to_string(i);
        if (sol.ds(s, min_sum, max_sum))
            ans++;
    }
    OUT(ans);
    return 0;
}

// 自己写过一遍后，再写确实用几乎一样的老思路，僵化，但能AC
// 连再犯一次 MOD 减 的负数 粗心 WA，都一模一样，还是没装进大脑里
