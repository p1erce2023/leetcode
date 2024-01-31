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
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using UMPII = unordered_map<int,int>;
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& E, int k, VVI& mem) {
        if (i==k || j==E.size()) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int ans=f(i, j+1, E, k, mem), nj;
        nj = upper_bound(E.begin(), E.end(), E[j][1], [](int val, auto& elem) {
            return elem[0] > val;
        }) - E.begin();
        ans = max(ans, E[j][2] + f(i+1, nj, E, k, mem));
        return mem[i][j] = ans;
    }
    int maxValue(vector<vector<int>>& E, int k) {
        sort(E.begin(), E.end());
        int n=E.size();
        VVI mem(k+1, VI(n+1, -1));
        return f(0, 0, E, k, mem);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VVI events; int k;
    events = {{1,2,4},{3,4,3},{2,3,1}}, k = 2;
    OUT(sol.maxValue(events, k));
    events = {{1,2,4},{3,4,3},{2,3,10}}, k = 2;
    OUT(sol.maxValue(events, k));
    events = {{1,1,1},{2,2,2},{3,3,3},{4,4,4}}, k = 3;
    OUT(sol.maxValue(events, k));
    return 0;
}
