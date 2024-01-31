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
    int nthUglyNumber(int n) {
        if (n==1) return 1;

        return x;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol.nthUglyNumber(10));
    OUT(sol.nthUglyNumber(1));
    OUT(sol.nthUglyNumber(11));
    OUT(sol.nthUglyNumber(12));
    return 0;
}
