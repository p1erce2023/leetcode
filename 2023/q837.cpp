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
    double new21Game(int n, int k, int maxPts) {
        if (k==0) return 1;
        vector<double> v(k+maxPts,0);
        v[0] = 1;
        double s=1;
        for (int i=1; i<min(n+1,k+maxPts); i++) {
            v[i] = s/maxPts;
            if (i<k) s += v[i];
            if (i>=maxPts) {
                s -= v[i-maxPts];
                v[i-maxPts]=0;
            }
        }
        s = 0;
        for (int i=k; i<=min(n,k+maxPts-1); i++) s += v[i];
        return s;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol.new21Game(1,0,2));
    OUT(sol.new21Game(1,0,1));
    OUT(sol.new21Game(21,17,10));
    return 0;
}
