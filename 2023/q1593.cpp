#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
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

class Solution {
public:
    int f(const string& s, unordered_set<string>& ss) {
        if (s.size() == 1) return ss.count(s)? 0 : 1;
        int ans=1, sf;
        for (int i=1; i<s.size(); i++) {
            const string& ps = s.substr(0,i);
            if (!ss.count(ps)) {
                ss.insert(ps);
                sf = f(s.substr(i), ss);
                if (sf) ans = max(ans, sf+1);
                ss.erase(ps);
            }
        }
        return ans;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> ss;
        return f(s, ss);
    }
};
/*
"aababab"
a ab aba b
a aba b ab

"aababaab"
a ab abaa b
a aba b aab

"aacab"
a ac ab
aa c a b

"aacbabb"
a ac b abb
aa cb ab b
aa c b a bb
*/
int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "aa";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "aaaaa";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "ababab";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "ababababa";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "ababccc";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "aba";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "aababaab";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "aababab";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "aacab";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    s = "aacbabb";
    std::cout << sol.maxUniqueSplit(s) << std::endl;
    return 0;
}
