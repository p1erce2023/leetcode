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
    int strStr(string haystack, string needle) {
        int n=needle.size(), m=haystack.size();
        vector<int> v(n,0);
        int i=1,j=0;
        while (i<n) {
            if (needle[i]==needle[j]) {
                v[i]=j+1;
                ++i, ++j;
            } else {
                while (j) {
                    j=v[j-1];
                    if (needle[i]==needle[j]) {
                        v[i]=j+1, ++j;
                        break;
                    }
                }
                ++i;
            }
        }
        i=0, j=0;
        while (i<m) {
            if (haystack[i]==needle[j]) {
                ++i,++j;
                if (j==n) return i-n;
            } else {
                if (j)
                    j=v[j-1];
                else
                    ++i;
            }
        }
        return -1;
    }
};

int main() {
    auto sol = Solution();
    string haystack, needle;
    // parameters init
    haystack = "sadbutsad", needle = "sad";
    OUT(sol.strStr(haystack, needle));
    haystack = "leetcode", needle = "leeto";
    OUT(sol.strStr(haystack, needle));
    haystack = "abc", needle = "aabaabaaa";
    OUT(sol.strStr(haystack, needle));
    haystack = "abxabcabcaby", needle = "abcaby";
    OUT(sol.strStr(haystack, needle));
    return 0;
}
// kmp