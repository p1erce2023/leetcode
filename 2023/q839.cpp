#include <algorithm>
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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    bool is_similar(string& a, string& b) {
        int dc=0;
        for (int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) {
                dc++;
                if (dc > 2) return false;
            }
        }
        return dc == 0 || dc == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int x, y, n=strs.size();
        vector<int> p(n);  // disjoint set
        unordered_set<int> g;
        p[0] = 0;
        for (int i=1; i<n; i++) {
            p[i] = i;
            for (int j=0; j<i; j++) {
                if (is_similar(strs[i], strs[j])) {
                    x = j;
                    while (p[x] != x) {
                        y = p[x];
                        p[x] = i;
                        x = y;
                    }
                    p[x] = i;
                }
            }
        }
        for (int i=0; i<n; i++) {
            x = i;
            while (p[x] != x) x = p[x];
            g.insert(x);
        }
        return g.size();
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> strs;
    strs = {"tars","rats","arts","star"};
    OUT(sol.numSimilarGroups(strs));
    strs = {"omv","ovm"};
    OUT(sol.numSimilarGroups(strs));
    strs = {"omv","omv"};
    OUT(sol.numSimilarGroups(strs));
    return 0;
}
