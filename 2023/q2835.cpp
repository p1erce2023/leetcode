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
using std::array;
using std::deque;
using std::string;
using std::vector;
using std::queue;
using std::priority_queue;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::max;
using std::min;
using std::next;
using std::distance;
using std::accumulate;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    int f(int i, int k, vector<int>& A, vector<unordered_map<int,int>>& dp) {
        if (i==A.size()) {
            if (k==0) return 0;
            else return INT_MAX;
        }
        if (dp[i].count(k)) return dp[i][k];
        int ans = INT_MAX;
        if (A[i] < k)
            return dp[i][k] = min(f(i+1, k, A, dp), f(i+1, k-A[i], A, dp));
        else if (A[i] == k)
            return 0;
        else {
            int x=0, y=0;
            while (k%2==0) {
                k /= 2;
                ++x;
            }
            for (y=0; y<32; y++)
                if (A[i] == (1<<y)) {
                    break;
                }
            return dp[i][k] = y-x;
        }
    }
    int minOperations(vector<int>& A, int k) {
        if (accumulate(A.begin(), A.end(), 0ll) < k)
            return -1;
        sort(A.begin(), A.end());
        int n=A.size();
        vector<unordered_map<int,int>> dp(n+1);
        return f(0, k, A, dp);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI A; int k;
    A = {64,32,2,8}, k = 5;
    OUT(sol.minOperations(A, k));
    A = {1,2,8}, k = 7;
    OUT(sol.minOperations(A, k));
    A = {1,32,1,2}, k = 12;
    OUT(sol.minOperations(A, k));
    A = {1,32,1}, k = 35;
    OUT(sol.minOperations(A, k));
    return 0;
}
