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
    vector<vector<int>> f(vector<int>& A) {
        int n=A.size(), s=accumulate(A.begin(), A.end(), 0);
        int sz = n/2+1;
        vector<vector<int>> ans(sz);
        for (int i=0, x, j, ss, k; i<(1<<n); ++i) {
            x=i, j=0, k=0, ss=0;
            while (x) {
                if (x&1) {
                    ss += A[j];
                    ++k;
                }
                ++j;
                x = x>>1;
            }
            if (k>=sz) continue;
            ans[k].push_back(s - 2*(s-ss));
        }
        for (auto& v : ans)
            sort(v.begin(), v.end());
        return ans;
    }
    int minimumDifference(vector<int>& A) {
        int n=A.size()/2;
        int ma=1<<n;
        vector<int> A1, A2;
        for (int i=0; i<n; ++i)
            A1.push_back(A[i]);
        for (int i=n; i<2*n; ++i)
            A2.push_back(A[i]);
        vector<vector<int>> a=f(A1), b=f(A2);
        int ans = INT_MAX;
        for (int x=0; x<(n/2+1); ++x) {
            for (int le : a[x]) {
                auto it = lower_bound(b[x].begin(), b[x].end(), le);
                if (it != b[x].end()) 
                    ans = min(ans, abs(*it - le));
                if (it != b[x].begin()) 
                    ans = min(ans, abs(*(next(it, -1)) - le));
            }
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI A;
    // A = {2,-1,0,4,-2,-9};
    // OUT(sol.minimumDifference(A));
    A = {34,23,30,77,85,47,96,94};
    OUT(sol.minimumDifference(A));
    return 0;
}
