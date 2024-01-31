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
    LL f(LL x, int limit, string& s) {
        auto sx = to_string(x);
        LL ans = 0;
        int n=sx.size(), m=s.size();
        for (int i=0; i<n-m; ++i) {
            if (sx[i]-'0' > limit) {
                ans += pow(limit+1, n-m-i);
                return ans;
            } else {
                ans += (sx[i]-'0') * pow(limit+1, n-m-i-1);
            }
        }
        if (n >= m) {
            for (int i=0; i<m; ++i) {
                sx[n-m+i] = s[i];
            }
            if (stoll(sx) <= x) ++ans;
        }
        return ans;
    }
    LL numberOfPowerfulInt(LL start, LL finish, int limit, string s) {
        return f(finish, limit, s) - f(start-1, limit, s);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int start, finish, limit; string s;
    start=10, finish=1844,limit=5,s="12";
    OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 3123, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 3124, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 3125, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 4123, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 4125, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 5001, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1, finish = 6000, limit = 4, s = "124";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 15, finish = 215, limit = 6, s = "10";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
    // start = 1000, finish = 2000, limit = 4, s = "3000";
    // OUT(sol.numberOfPowerfulInt(start, finish, limit, s));
}

/*
又是一道 digit manipulation 的题，十进制
*/