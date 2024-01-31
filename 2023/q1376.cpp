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
    int f(int i, vector<int>& t, vector<int>& manager, vector<int>& informTime) {
        if (t[i] != -1) return t[i];
        int j = manager[i];
        return t[i] = informTime[j] + f(j, t, manager, informTime);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> t(n,-1);
        t[headID] = 0;
        int ans=0, j, x;
        for (int i=0; i<n; i++)
            ans = max(ans, f(i, t, manager, informTime));
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n, headID; vector<int> manager,informTime;
    n = 8, headID = 2, manager = {2,2,-1,2,2,2,1,3}, informTime = {0,2,1,3,0,0};
    OUT(sol.numOfMinutes(n,headID,manager,informTime));
    n = 1, headID = 0, manager = {-1}, informTime = {0};
    OUT(sol.numOfMinutes(n,headID,manager,informTime));
    return 0;
}
