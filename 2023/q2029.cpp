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

class Solution {
public:
    bool f(int t, int res, int a, int b, int c) {
        bool ans = false;
        if (a==0 && b==0 && c==0) {
            if (t==0) return true;
            else return false;
        }
        if (res == 1) {
            if ((a && !f(1-t, 1, a-1, b, c)) || (b && !f(1-t, 2, a, b-1, c)))
                ans = true;
        } else {
            if ((a && !f(1-t, 2, a-1, b, c)) || (c && !f(1-t, 1, a, b, c-1)))
                ans = true;
        }
        return ans;
    }
    bool stoneGameIX(vector<int>& A) {
        array<int, 3> v={0,0,0};
        for (int a : A)
            v[a%3]++;
        v[0] = v[0] % 2;
        if (v[1] && !f(0, 1, v[0], v[1]-1, v[2]))
            return true;
        if (v[2] && !f(0, 2, v[0], v[1], v[2]-1))
            return true;
        return false;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI A;
    A = {5,1,2,4,3};
    OUT(sol.stoneGameIX(A));
    return 0;
}
