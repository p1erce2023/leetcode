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
    vector<long long> kthPalindrome(vector<int>& Q, int sz) {
        int x=sz/2, n=Q.size(), k=1, base, bound;
        if (sz == 1) {
            vector<LL> ans(n);
            for (int i=0; i<n; ++i)
                if (Q[i]>=10) ans[i] = -1;
                else ans[i] = Q[i];
            return ans;
        }
        for (int j=1; j<x; ++j) k *= 10;
        base = k;
        k *= 10;
        if (sz%2) base *= 10;
        bound = base*9;
        --base;
        vector<LL> ans(n);
        for (int i=0; i<n; ++i) {
            if (Q[i]>bound)
                ans[i] = -1;
            else {
                LL y=base+Q[i], z, ry=0;
                z = y;
                if (sz%2) z = y/10;
                while (z) {
                    ry = ry * 10 + z % 10;
                    z /= 10;
                }
                ans[i] = y * k + ry;
            }
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI queries; int intLength;
    queries = {1,2,3,4,5,90}, intLength = 3;
    for (auto vi : sol.kthPalindrome(queries, intLength)) { std::cout << vi << ' '; }
    std::cout << std::endl;

    queries = {1,2,3,4,5,9,90}, intLength = 2;
    for (auto vi : sol.kthPalindrome(queries, intLength)) { std::cout << vi << ' '; }
    std::cout << std::endl;

    queries = {2,201429812,8,520498110,492711727,339882032,462074369,9,7,6}, intLength = 1;
    for (auto vi : sol.kthPalindrome(queries, intLength)) { std::cout << vi << ' '; }
    std::cout << std::endl;

    return 0;
}
