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
    int maxVowels(string s, int k) {
        int n=s.size(), ans=0;
        vector<int> vowel(26,0), ps(n+1,0);
        string vowels = "aeiou";
        for (char c : vowels) vowel[c-'a'] =1;
        for (int i=1; i<=n; i++) ps[i] = ps[i-1] + vowel[s[i-1]-'a'];
        for (int i=k; i<=n; i++) ans = max(ans, ps[i]-ps[i-k]);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    string s; int k;
    // parameters init
    s = "abciiidef", k = 3;
    OUT(sol.maxVowels(s, k));
    return 0;
}
