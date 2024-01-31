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
    int kIncreasing(vector<int>& A, int k) {
        int ans=0, n=A.size(), lis=0;
        vector<int> v;
        for (int kk=0; kk<k; ++kk) {
            v.clear();
            for (int i=kk; i<n; i+=k) {
                auto it = upper_bound(v.begin(), v.end(), A[i]);
                if (it == v.end())
                    v.push_back(A[i]);
                else
                    *it = A[i];
            }
            lis += v.size();
        }
        return n - lis;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
