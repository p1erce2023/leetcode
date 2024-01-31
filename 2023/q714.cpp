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
    int maxProfit(vector<int>& A, int fee) {
        int p0=0,p1=-A[0],np0=0,np1=-A[0];
        for (int i=1; i<A.size(); i++) {
            np0 = max(p0, p1+A[i]-fee);
            np1 = max(p1, p0-A[i]);
            p0=np0, p1=np1;
        }
        return p0;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> prices; int fee;
    prices = {1,3,2,8,4,9}, fee = 2;
    OUT(sol.maxProfit(prices,fee));
    prices = {1,3,7,5,10,3}, fee = 3;
    OUT(sol.maxProfit(prices,fee));
    return 0;
}
