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
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
        int m=A.size(), n=B.size(), p=(m+n)/2;
        bool odd=(m+n)%2;
        if (m==0) {
            if (odd) return B[p];
            else return (B[p-1]+B[p])/2.0;
        }
        if (n==0) {
            if (odd) return A[p];
            else return (A[p-1]+A[p])/2.0;
        }
        int left=0, right=m, pa, pb, amin, amax, bmin, bmax;
        while (left < right) {
            pa = left + (right - left) / 2;
            pb = p - pa;
            if (pa) 
                amin = A[pa-1];
            else 
                amin = INT_MIN;
            amax = A[pa];
            if (pb >= n) 
                bmin = B[n-1], bmax = INT_MAX;
            else if (pb)
                bmin = B[pb-1], bmax = B[pb];
            else
                bmin = INT_MIN, bmax = B[pb];
            if (amax >= bmin) {
                if (bmax >= amin) {
                    left = pa;
                    break;
                }
                right = pa;
            } else
                left = pa + 1;
        }
        if (odd) {
            return min(A[left], B[p-left]);
        } else {
            int s = min(A[left], B[p-left]);
            s += max(A[left-1], B[p-left-1]);
            return s / 2.0;
        }
    }
};

double f(const VI& A, const VI& B) {
    VI C = A;
    for (int b : B) C.push_back(b);
    sort(C.begin(), C.end());
    int n=C.size();
    if (n & 1) 
        return C[n/2];
    else
        return (C[n/2-1] + C[n/2])/2.0;
}

int main() {
    auto sol = Solution();
    // parameters init
    VI A, B;
    A = {1}, B = {2};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {1,5,8}, B = {2,4,7,9,10};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {0,0,0,0,0}, B = {-1,0,0,0,0,0,1};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {1,5,8}, B = {2,4,7,9,10,11};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {1,5,8}, B = {2,4,7};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {1}, B = {2,3};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {11,13}, B = {2};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {1}, B = {};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    A = {1,3,4,5}, B = {};
    cout << sol.findMedianSortedArrays(A, B) << ' ' << f(A, B) << '\n';
    return 0;
}
