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
    int longestStrChain(vector<string>& W) {
        int ans=1;
        string s;
        vector<unordered_map<string,int>> vc(17);
        for (auto& w : W) vc[w.size()][w]=1;
        for (int i=2; i<17; i++) {
            if (vc[i].empty() || vc[i-1].empty()) continue;
            for (auto& [k,v] : vc[i]) {
                for (int j=0; j<k.size(); j++) {
                    s = k;
                    s.erase(j,1);
                    if (vc[i-1].count(s)) {
                        v = max(v, vc[i-1][s]+1);
                        ans = max(ans, v);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> words;
    words = {"a","b","ba","bca","bda","bdca"};
    OUT(sol.longestStrChain(words));
    return 0;
}
