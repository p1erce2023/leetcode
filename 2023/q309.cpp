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
        int p0=0, p0_sold=0, p1=-A[0], np0=0, np1=-A[0], np0_sold=0;
        for (int i=1; i<A.size(); i++) {
            np0 = max({p0, p0_sold});
            np1 = max(p1, p0-A[i]);
            np0_sold = max(p0_sold, p1+A[i]);
            p0=np0,p1=np1,p0_sold=np0_sold;
        }
        return np0_sold;
    }
    // 不是一点点牛啊
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> prices;
    prices = {5,3,6,1,3,7,9};
    OUT(sol.maxProfit(prices));
    prices = {1,2,3,0,2};
    OUT(sol.maxProfit(prices));
    prices = {1};
    OUT(sol.maxProfit(prices));
    prices = {1,4,5,0,2};
    OUT(sol.maxProfit(prices));
    prices = {1,2};
    OUT(sol.maxProfit(prices));
    return 0;
}
