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
    using LL=long long;
    int m, n;
    LL f(int i, int j, int t, vector<int>& R, vector<vector<int>>& F, vector<vector<vector<LL>>>& mem) {
        if (i==m) return 0;
        if (j==n) return -1;
        if (mem[i][j][t] != -1)
            return mem[i][j][t];
        LL ans=-1, x, d=abs(R[i]-F[j][0]);
        if (t+1<F[j][1]) {
            x = f(i+1,j,t+1,R,F,mem);
        } else {
            x = f(i+1,j+1,0,R,F,mem);
        }
        if (x != -1) ans = d + x;
        x = f(i,j+1,0,R,F,mem);
        if (x != -1) {
            if (ans==-1) ans=x;
            else ans = min(ans, x);
        }
        return mem[i][j][t] = ans;
    }
    long long minimumTotalDistance(vector<int>& R, vector<vector<int>>& F) {
        sort(R.begin(), R.end());
        F.erase(std::remove_if(F.begin(), F.end(), [](vector<int>& it){
            return it[1]==0;
        }), F.end());
        sort(F.begin(), F.end());
        m=R.size(), n=F.size();
        int maxLM=F[0][1];
        for (auto& fac : F) maxLM=max(maxLM,fac[1]);
        vector<vector<vector<LL>>> mem(m, vector<vector<LL>>(n, vector<LL>(maxLM, -1)));
        return f(0,0,0,R,F,mem);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> robot; vector<vector<int>> factory;
    robot = {670355988,403625544,886437985,224430896,126139936,-477101480,-868159607,-293937930}, factory = {{333473422,7},{912209329,7},{468372740,7},{-765827269,4},{155827122,4},{635462096,2},{-300275936,2},{-115627659,0}};
    OUT(sol.minimumTotalDistance(robot,factory));
    robot = {0,4,6}, factory = {{2,2},{6,2}};
    OUT(sol.minimumTotalDistance(robot,factory));
    robot = {1,-1}, factory = {{-2,1},{2,1}};
    OUT(sol.minimumTotalDistance(robot,factory));
    return 0;
}
