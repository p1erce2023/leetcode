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
    long long sumScores(string s) {
        int n=s.size(), j=0, i=1;
        vector nx(n, -1);
        while (i<n) {
            if (s[i] == s[j]) {
                nx[i] = j;
                ++j; ++i;
            } else {
                if (j)
                    j = nx[j-1] + 1;
                else 
                    ++i;
            }
        }
        long long ans = 0;
        for (int k=0; k<n; ++k)
            ans += nx[k]+1;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "babab";
    OUT(sol.sumScores(s));
    s = "azbazbzaz";
    OUT(sol.sumScores(s));
    return 0;
}
