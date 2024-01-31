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
    int dp[101][2][10];
    int MOD = 1e9+7;
    string substract(string& s) {
        int i, n=s.size();
        string x = s;
        for (i=n-1; i>=0; --i) {
            if (x[i] > '0') {
                x[i] -= 1;
                if (x[i]==0 && i==0) return string(n-1, '9');
                break;
            }
        }
        ++i;
        while (i < n)
            x[i++] = '9';
        return x;
    }
    int f(string& s, int k, bool sm, int i) {
        if (i == s.size()) return 1;
        if (dp[i][sm][k] != -1) 
            return dp[i][sm][k];
        int ans = 0;
        if (k>=1 && (sm || k-1 <= s[i]-'0'))
            ans = (ans + f(s, k-1, sm || k-1<s[i]-'0', i+1)) % MOD;
        if (k<9 && (sm || k+1 <= s[i]-'0'))
            ans = (ans + f(s, k+1, sm || k+1<s[i]-'0', i+1)) % MOD;
        return dp[i][sm][k] = ans;
    }
    int f2(string& s) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int k=1; k<=s[0]-'0'; ++k)
            ans = (ans + f(s, k, k<s[0]-'0', 1)) % MOD;
        for (int i=1; i<s.size(); ++i)
            for (int k=1; k<=9; ++k)
                ans = (ans + f(s, k, true, i+1)) % MOD;
        return ans;
    }
    int countSteppingNumbers(string low, string high) {
        auto lb = substract(low);
        return (f2(high) + MOD - f2(lb)) % MOD;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string low, high;
    low = "90", high = "101";
    OUT(sol.countSteppingNumbers(low, high));
    low = "1", high = "11";
    OUT(sol.countSteppingNumbers(low, high));
    low = "12344321", high = "1122334455667788";
    OUT(sol.countSteppingNumbers(low, high));
    low = "20", high = "111";
    OUT(sol.countSteppingNumbers(low, high));
    return 0;
}
