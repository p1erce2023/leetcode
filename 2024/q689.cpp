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
    vector<int> maxSumOfThreeSubarrays(vector<int>& A, int k) {
        int n = A.size(), b = 0;
        vector<int> s1(n + k, 0), s2(n + k, 0), s3(n + k, 0);
        vector<int> idx1(n + k, 0), idx2(n + k, 0), idx3(n + k, 0);
        for (int i=0, j; i<n; ++i) {
            j = n-1-i;
            b += A[j];
            if (k < i + 1)
                b -= A[j+k];
            if (b >= s1[j+1]) {
                s1[j] = b;
                idx1[j] = j;
            } else {
                s1[j] = s1[j+1];
                idx1[j] = idx1[j+1];
            }
            if (b + s1[j+k] >= s2[j+1]) {
                s2[j] = b + s1[j+k];
                idx2[j] = j;
            } else {
                s2[j] = s2[j+1];
                idx2[j] = idx2[j+1];
            }
            if (b + s2[j+k] >= s3[j+1]) {
                s3[j] = b + s2[j+k];
                idx3[j] = j;
            } else {
                s3[j] = s3[j+1];
                idx3[j] = idx3[j+1];
            }
        }
        int i1 = idx3[0];
        int i2 = idx2[i1 + k];
        int i3 = idx1[i2 + k];
        return {i1, i2, i3};
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> A = {1,2,1,2,6,7,5,1};
    int k = 2;
    auto res = sol.maxSumOfThreeSubarrays(A, k);
    for (auto& elem : res)
      OUT(elem);
}
