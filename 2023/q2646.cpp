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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    bool f1(int s, int t, vector<int>& c, vector<vector<int>>& e, int p=-1) {
        if (s == t) return true;
        for (int x : e[s]) {
            if (x == p) continue;
            if (f1(x,t,c,e,s)) {
                c[x]++;
                return true;
            }
        }
        return false;
    }

    int f2(int x, int p, vector<int>& dp, vector<int>& c, vector<vector<int>>& e, vector<int>& price) {
        if (dp[x] != -1) return dp[x];
        int s2=c[x]*price[x], s1=s2/2;
        for (int y : e[x]) {
            if (y == p) continue;
            s1 += c[y]*price[y];
            s2 += f2(y,x,dp,c,e,price);
            for (int yy : e[y]) {
                if (yy == x) continue;
                s1 += f2(yy,y,dp,c,e,price);
            }
        }
        dp[x] = min(s1,s2);
        return dp[x];
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> e(n, vector<int>());
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        vector<int> c(n,0), dp(n,-1);
        for (auto& trip : trips) {
            c[trip[0]]++;
            f1(trip[0], trip[1], c, e);  // trips.length * O(n)
        }
        return f2(0,-1,dp,c,e,price);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n; vector<vector<int>> edges, trips; vector<int> price;
    n = 4, edges = {{0,1},{1,2},{1,3}}, price = {2,2,10,6}, trips = {{0,3},{2,1},{2,3}};
    OUT(sol.minimumTotalPrice(n,edges,price,trips));
    n = 2, edges = {{0,1}}, price = {2,2}, trips = {{0,0}};
    OUT(sol.minimumTotalPrice(n,edges,price,trips));
    n=50, edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10},{10,11},{11,12},{12,13},{13,14},{14,15},{15,16},{16,17},{17,18},{18,19},{19,20},{20,21},{21,22},{22,23},{23,24},{24,25},{25,26},{26,27},{27,28},{28,29},{29,30},{30,31},{31,32},{32,33},{33,34},{34,35},{35,36},{36,37},{37,38},{38,39},{39,40},{40,41},{41,42},{42,43},{43,44},{44,45},{45,46},{46,47},{47,48},{48,49}}, price = {2,820,460,262,598,192,758,922,266,628,74,720,614,304,716,764,110,328,344,160,884,80,154,424,858,466,602,114,432,140,726,438,774,346,944,596,974,552,536,564,938,888,376,980,502,196,80,870,1000,998}, trips ={{9,9}};
    OUT(sol.minimumTotalPrice(n,edges,price,trips));
    return 0;
}