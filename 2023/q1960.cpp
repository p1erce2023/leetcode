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
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(1, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

class Solution {
public:
    // 纯纯的 manacher algorithm
    int eds[100001], bes[100001];
    long long maxProduct(string s) {
        memset(eds, 0, sizeof(eds));
        memset(bes, 0, sizeof(bes));
        int n=s.size();
        auto p = manacher_odd(s);
        for (int i=0; i<n; ++i) {
            eds[i+p[i]-1] = max(eds[i+p[i]-1], p[i]*2-1);
            bes[i-p[i]+1] = max(bes[i-p[i]+1], p[i]*2-1);
        }
        for (int i=0; i<n-1; ++i) {
            eds[n-2-i] = max(eds[n-2-i], eds[n-1-i]-2);
            bes[i+1] = max(bes[i+1], bes[i]-2);
        }
        for (int i=0; i<n-1; ++i) {
            eds[i+1] = max(eds[i+1], eds[i]);
            bes[n-2-i] = max(bes[n-2-i], bes[n-1-i]);
        }
        long long ans = 0;
        for (int i=0; i<n-1; ++i)
            ans = max(ans, 1ll * eds[i] * bes[i+1]);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "xabacabac";
    OUT(sol.maxProduct(s));
    s = "ababbb";
    OUT(sol.maxProduct(s));
    s = "zaaaxbbby";
    OUT(sol.maxProduct(s));
    return 0;
}
