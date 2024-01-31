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
    int nextGreaterElement(int n) {
        long long x = n, ma=0x7fffffff, j=1;
        vector<int> d = {n % 10};
        n /= 10;
        int r, y;
        while (n) {
            r = n % 10;
            n /= 10;
            if (r >= d.back()) d.push_back(r);
            else {
                for (int i=0; i<d.size(); i++) {
                    x -= d[i] * j;
                    j *= 10;
                }
                x -= r * j;
                y = 0;
                while (d[y]<=r) y++;
                swap(r, d[y]);
                reverse(d.begin(), d.end());
                j = 1;
                for (int i=0; i<d.size(); i++) {
                    x += d[i] * j;
                    j *= 10;
                }
                x += r*j;
                if (x > ma) return -1;
                return x;
            }
        }
        return -1;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n=12;
    // OUT(sol.nextGreaterElement(n));
    // n=21;
    // OUT(sol.nextGreaterElement(n));
    n=230241;
    OUT(sol.nextGreaterElement(n));
    return 0;
}
