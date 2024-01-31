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
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end());
        int left=0, right=c.size(), mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (distance(lower_bound(c.begin(), c.end(), mid), c.end()) >= mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> c;
    c = {3,0,6,1,5};
    OUT(sol.hIndex(c));
    c = {1,3,1};
    OUT(sol.hIndex(c));
    return 0;
}
