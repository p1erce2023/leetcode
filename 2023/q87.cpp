#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::map;
using std::priority_queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    bool isScramble(string s1, string s2, map<pair<string, string>, bool>& mmp) {
        // std::cout << s1 << ' ' << s2 << std::endl;
        if (s1 == s2) return true;
        if (mmp.find({s1,s2}) != mmp.end()) {
            std::cout << "rep " << s1 << ' ' << s2 << std::endl;
            return mmp[{s1,s2}];
        } else {
            std::cout << "    " << s1 << ' ' << s2 << std::endl;
        }
        int n = s1.size();
        vector<int> c(26,0);
        for (int i=0; i<n; i++) {c[s1[i] - 'a']++; c[s2[i] - 'a']--;}
        for (int v : c) if (v != 0) {mmp[{s1,s2}] = false;return false;}
        for (int i=1; i<n; i++) {
            if (isScramble(s1.substr(0,i),s2.substr(0,i),mmp) && isScramble(s1.substr(i),s2.substr(i),mmp)) {
                mmp[{s1,s2}] = true;
                return true;
            }
            if (isScramble(s1.substr(0,i),s2.substr(n-i),mmp) && isScramble(s1.substr(i),s2.substr(0,n-i),mmp)) {
                mmp[{s1,s2}] = true;
                return true;
            }
        }
        mmp[{s1,s2}] = false;
        return false;
    }
    bool isScramble(string s1, string s2) {
        map<pair<string, string>, bool> mmp;
        return isScramble(s1,s2,mmp);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s1, s2;
    // s1 = "great", s2 = "rgeat";
    // std::cout << sol.isScramble(s1, s2) << std::endl;
    // s1 = "abcde", s2 = "caebd";
    // std::cout << sol.isScramble(s1, s2) << std::endl;
    // s1 = "a", s2 = "a";
    // std::cout << sol.isScramble(s1, s2) << std::endl;
    // s1 = "abcdbdacbdac", s2 = "bdacabcdbdac";
    // std::cout << sol.isScramble(s1, s2) << std::endl;
    s1 = "eebaacbcbcadaaedceaaacadccd", s2 = "eadcaacabaddaceacbceaabeccd";
    std::cout << sol.isScramble(s1, s2) << std::endl;
    return 0;
}
// abc acb bac bca cab cba