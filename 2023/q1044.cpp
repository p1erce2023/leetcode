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
using std::string_view;
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
    string f(string& s, int x) {
        unordered_set<string_view> c;
        for (int i=0; i<=s.size()-x; i++)
            if (!c.emplace(s.data()+i,x).second)
                return s.substr(i,x);
        return "";
    }
    string longestDupSubstring(string s) {
        int left=0,right=s.size(),mid;
        string dup, ans;
        while (left < right) {
            mid = (left + right) / 2;
            dup = f(s,mid);
            if (dup.empty())
                right = mid;
            else
                left = mid+1, ans=dup;
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    // s = "nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy";
    // OUT(sol.longestDupSubstring(s));
    s = "aa";
    OUT(sol.longestDupSubstring(s));
    return 0;
}
