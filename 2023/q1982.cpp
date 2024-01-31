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

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& s) {
        sort(s.begin(), s.end());
        for (auto vi : s) { std::cout << vi << ' '; }
        std::cout << std::endl;
        return {};
    }
    vector<int> genArray(vector<int>& A) {
        vector<int> ans;
        for (int i=0, n=A.size(), x, j, s; i<(1<<n); ++i) {
            x = i, j = 0, s = 0;
            while (x) {
                if (x & 1)
                    s += A[j];
                ++j;
                x >>= 1;
            }
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    // int n; VI sums;
    // n = 4, sums = {0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8};
    // for (auto vi : sol.recoverArray(n, sums)) { std::cout << vi << ' '; }
    // std::cout << std::endl;
    VI A;
    A = {1,2,4,5,7,9,11,19};
    for (auto vi : sol.genArray(A)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
