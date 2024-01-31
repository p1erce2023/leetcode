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
    bool 
    bool possiblyEquals(string s1, string s2) {
        return f(0, 0, 0, 0, s1, s2);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
