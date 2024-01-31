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
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        vector<int> le(n, 0), ri(n,0), v;
        int mi; bool continous;
        mi = 0, continous = true;
        for (int i=0; i<n; ++i) {
            if (s[i] == '1') {
                v.push_back(i);
                if (continous) {
                    mi++;
                } else {
                    if (mi+2>i+1) {
                        continous = true;
                        mi = i+1;
                    } else {
                        mi += 2;
                    }
                }
                le[i] = mi;
            } else {
                continous = false;
            }
        }
        mi = 0, continous = true;
        for (int i=n-1; i>=0; --i) {
            if (s[i] == '1') {
                if (continous) {
                    mi++;
                } else {
                    if (mi+2>n-i) {
                        continous = true;
                        mi = n-i;
                    } else {
                        mi += 2;
                    }
                }
                ri[i] = mi;
            } else {
                continous = false;
            }
        }
        if (v.empty()) return 0;
        int m=v.size();
        int ans = min(le[v[m-1]], ri[v[0]]);
        for (int i=0; i<m-1; ++i)
            ans = min(ans, le[v[i]] + ri[v[i+1]]);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "1100101";
    OUT(sol.minimumTime(s));
    s = "0010";
    OUT(sol.minimumTime(s));
    return 0;
}
