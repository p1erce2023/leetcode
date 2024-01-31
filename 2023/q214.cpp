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
    string process(string &t) {
        int n=t.size();
        string ans(2*n+1, '#');
        for (int i=0; i<n; i++) ans[2*i+1] = t[i];
        return ans;
    }
    string shortestPalindrome(string s) {
        if (s.size() < 2) return s;
        string ss = process(s);
        int n=ss.size(), c=1, r=1, oldc, oldr, mc, ma_r, max_palin=1;
        vector<int> v(n,0);
        while (c<=n/2) {
            while (c-r>=0 && c+r<n && ss[c-r]==ss[c+r]) r++;
            v[c] = --r;
            if (c==r) max_palin = r;
            oldc = c, oldr = r;
            c++;
            r = 0;
            while (c < oldc+oldr && c<=n/2) {
                mc = oldc - (c-oldc);
                ma_r = oldc+oldr-c;
                if (v[mc] < ma_r) {
                    v[c++] = v[mc];
                } else if (v[mc] > ma_r) {
                    v[c++] = ma_r;
                } else {
                    r = v[mc]; break;
                }
            }
        }
        string res=s.substr(max_palin);
        string ans(res.rbegin(), res.rend());
        ans += s;
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "acecececececaaa";
    std::cout << s << ' ' << sol.shortestPalindrome(s) << '\n';
    s = "aacecaaa";
    std::cout << s << ' ' << sol.shortestPalindrome(s) << '\n';
    s = "abcd";
    std::cout << s << ' ' << sol.shortestPalindrome(s) << '\n';
    s = "";
    std::cout << s << ' ' << sol.shortestPalindrome(s) << '\n';
    s = "abcdcb";
    std::cout << s << ' ' << sol.shortestPalindrome(s) << '\n';
    return 0;
}
