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
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::max;
using std::min;
using std::next;
using std::distance;
using std::lower_bound;
using std::upper_bound;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    int f(int i, int j, vector<int>& p, vector<vector<int>>& mem) {
        if (i+1>=j) return 0;
        else if (i+2==j) return min(p[i+1]-p[i], p[i+2]-p[i+1]);
        if (mem[i][j] != -1) return mem[i][j];
        int le, ri, ans=0;
        for (int k=i+1; k<=j; k++) {
            le = p[k]-p[i], ri = p[j]-p[k];
            if (le < ri) {
                ans = max(ans, le + f(i,k,p,mem));
            } else if (le == ri) {
                ans = max(ans, le + max(f(i,k,p,mem), f(k,j,p,mem)));
            } else {
                ans = max(ans, ri + f(k,j,p,mem));
            }
        }
        return mem[i][j] = ans;
    }
    int stoneGameV(vector<int>& A) {
        int n=A.size();
        if (n==1) return 0;
        vector<int> prefsum(n+1,0);
        prefsum[0] = 0;
        for (int i=0; i<n; i++) prefsum[i+1] = prefsum[i] + A[i];
        vector<vector<int>> mem(n+1, vector<int>(n+1, -1));
        return f(0,n,prefsum,mem);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> stoneValue;
    stoneValue = {98,77,24,49,6,12,2,44,51,96};
    OUT(sol.stoneGameV(stoneValue));
    stoneValue = {6,2,3,4,5,5};
    OUT(sol.stoneGameV(stoneValue));
    stoneValue = {7,7,7,7,7,7,7};
    OUT(sol.stoneGameV(stoneValue));
    stoneValue = {4};
    OUT(sol.stoneGameV(stoneValue));
    return 0;
}
