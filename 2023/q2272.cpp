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
    int f(char a, char b, string& s) {
        bool prev_b = false;
        int ca=0, cb=0, ans=0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == a) {
                ++ca;
                if (cb) ans = max(ans, ca - cb);
            } else if (s[i] == b) {
                if (ca==0) {
                    if (!prev_b)
                        prev_b = true, cb = 1;
                } else {
                    if (prev_b) {
                        prev_b = false;
                    } else {
                        ++cb;
                        if (cb > ca)
                            ca = 0, cb = 1, prev_b = true;
                    }
                    ans = max(ans, ca - cb);
                }
            }
        }
        return ans;
    }
    int largestVariance(string s) {
        unordered_set<char> cs;
        for (char c : s) cs.insert(c);
        int ans=0;
        for (char a : cs)
            for (char b : cs) {
                if (a == b) continue;
                ans = max(ans, f(a, b, s));
            }
        return ans;
    }
};

class Solution2 {
public:
    int largestVariance(string s) {
    int res = 0;
    unordered_set<char> unique(begin(s), end(s));
    for (char a : unique)
        for (char b : unique) {
            if (a == b) continue;
            int var = 0, has_b = 0, first_b = 0;
            for (auto ch : s) {
                var += ch == a;
                if (ch == b) {
                    has_b = true;
                    if (first_b && var >= 0)
                        first_b = false;
                    else if (--var < 0) {
                        first_b = true;
                        var = -1;
                    }
                }
                res = max(res, has_b ? var : 0);
            }
        }
    return res;
}
};

int main() {
    auto sol = Solution();
    auto sol2 = Solution2();
    // parameters init
    string s;
    // s = "aababbb";
    // OUT(sol.largestVariance(s));
    // s = "abcde";
    // OUT(sol.largestVariance(s));
    // s = "lripaa";
    // OUT(sol.largestVariance(s));
    // s = "ababab";
    // OUT(sol.largestVariance(s));
    // s = "dsyemilsuwhciclqwprizywgkwkbgcqhtcwfvlw";
    // OUT(sol.largestVariance(s));
    s = "aaaab";
    OUT(sol.largestVariance(s));
    OUT(sol2.largestVariance(s));
    // s = "baaa";
    // OUT(sol.largestVariance(s));
    // s = "baaac";
    // OUT(sol.largestVariance(s));
    // s = "aaaaabbba";
    // OUT(sol.largestVariance(s));
    // s = "abbacbccaaa";
    // OUT(sol.largestVariance(s));
    // s = "abbabcbccaaa";
    // OUT(sol.largestVariance(s));
    return 0;
}
