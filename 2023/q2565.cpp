#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
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
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size(), i, j, k;
        vector<int> suffix(m, -1);
        for (i=n-1,j=m-1; i>=0 && j>=0; i--)
            if (s[i] == t[j]) {
                suffix[j--] = i;
            }
        j++;
        int ans = j;
        if (ans == 0) return 0;
        for (i=0,k=0; i<n && k<m; i++)
            if (s[i] == t[k]) {
                for (; j < m && suffix[j] <= i; j++);
                ans = min(ans, j-(++k));
            }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    string s, t;
    s = "abacaba", t = "bzaa";
    std::cout << sol.minimumScore(s, t) << " 1" << std::endl;
    s = "cde", t = "xyz";
    std::cout << sol.minimumScore(s, t) << " 3" << std::endl;
    s = "eeecaeecdeeadcdbcaa", t = "edecabe";
    std::cout << sol.minimumScore(s, t) << " 2" << std::endl;
    s = "abecdebe", t = "eaebceae";
    std::cout << sol.minimumScore(s, t) << " 6" << std::endl;
    return 0;
}
