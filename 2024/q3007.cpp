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
    LL f(LL y, int x) {
        LL ans = 0;
        for (int i=1; i<=64; ++i) {
            if (i % x) continue;
            LL res = y >> i;
            ans += res << (i-1);
            ans += res;
            LL t = 1ll << (i-1);
            LL yy = (y | t) & (~(t-1));
            ans += max(y - yy + 1, 0ll);
            if (res == 0) break;
        }
        return ans;
    }
    long long findMaximumNumber(long long k, int x) {
        f(7, 1);
        LL left=0, right=1ll<<47, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (f(mid, x) > k)
                right = mid;
            else
                left = mid + 1;
        }
        return left - 1;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    LL k; int x;
    k = 9, x = 1;
    OUT(sol.findMaximumNumber(k, x));
}

/*
挺有意思的数学题，数位，digit manipulation，脑子转的太慢了
*/