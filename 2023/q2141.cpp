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
using std::accumulate;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;

class Solution {
public:
    bool f(LL x, int n, vector<int>& A) {
        int k=0;
        LL res=0;
        for (int a : A) {
            if (a > x) {
                ++k;
                if (k >= n) return true;
            } else {
                res += a;
                if (res >= x) {
                    res -= x;
                    ++k;
                    if (k >= n) return true;
                }
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& A) {
        sort(A.begin(), A.end(), std::greater<>());
        LL left=1, right=1e14+1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (f(mid, n, A))
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
    int n; VI A;
    n = 2, A = {3,3,3};
    OUT(sol.maxRunTime(n, A));
    n = 2, A = {1,1,1,1};
    OUT(sol.maxRunTime(n, A));
    n = 3, A = {10,10,3,5};
    OUT(sol.maxRunTime(n, A));
    n = 12, A = {11,89,16,32,70,67,35,35,31,24,41,29,6,53,78,83};
    OUT(sol.maxRunTime(n, A));
    return 0;
}
