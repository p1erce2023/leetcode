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
    int maxProfit(vector<int>& A) {
        vector<int> b1(2,-A[0]), s1(2,-1), b2(2,-1e5), s2(2,0);
        for (int i=1; i<A.size(); i++) {
            b1[1] = max(b1[0], -A[i]);
            s1[1] = max(s1[0], b1[0]+A[i]);
            if (s1[0] != -1)
                b2[1] = max(b2[0], s1[0]-A[i]);
            if (b2[0] != -1e5)
                s2[1] = max(s2[0], b2[0]+A[i]);
            b1[0]=b1[1], s1[0]=s1[1], b2[0]=b2[1], s2[0]=s2[1];
        }
        return max(s1[0],s2[0]);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> prices;
    prices = {3,3,5,0,0,3,1,4};
    OUT(sol.maxProfit(prices));
    prices = {1,2,3,4,5};
    OUT(sol.maxProfit(prices));
    prices = {7,6,4,3,1};
    OUT(sol.maxProfit(prices));
    return 0;
}
