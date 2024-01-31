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
    int maxProfit(int k, vector<int>& A) {
        vector<vector<int>> b(k,vector<int>(2,-A[0])), s(k,vector<int>(2,0));
        for (int i=1; i<A.size(); i++) {
            b[0][1] = max(b[0][0], -A[i]);
            s[0][1] = max(s[0][0], b[0][0]+A[i]);
            for (int j=1; j<k; j++) {
                b[j][1] = max(b[j][0], s[j-1][0]-A[i]);
                s[j][1] = max(s[j][0], b[j][0]+A[i]);
            }
            for (int j=0; j<k; j++)
                b[j][0] = b[j][1], s[j][0] = s[j][1];
        }
        int ans=0;
        for (int i=0; i<k; i++) ans = max(ans, s[i][0]);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int k; vector<int> prices;
    // k = 2, prices = {2,4,1};
    // OUT(sol.maxProfit(k,prices));
    // k = 2, prices = {3,2,6,5,0,3};
    // OUT(sol.maxProfit(k,prices));
    k = 2, prices = {1,2,4,2,5,7,2,4,9,0};
    OUT(sol.maxProfit(k,prices));
    return 0;
}
