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
    int f2 (string& s, int i, int j) {
        int ans = 0;
        while (i < j)
            if (s[i++] != s[j--]) ans++;
        return ans;
    }
    int f(string& s, int i, int n, int k, vector<vector<int>>& mem) {
        if (k==1) {
            return f2(s, i, n-1);
        } else if (mem[i][k] != -1) {
            return mem[i][k];
        } else {
            int ans=n;
            for (int j=i; j<n-k+1; j++)
                if (f(s,j+1,n,k-1,mem) != -1)
                    ans = min(ans, f2(s,i,j) + f(s,j+1,n,k-1,mem));
            if (ans == n) return -1;
            else return mem[i][k] = ans;
        }
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> mem(n, vector<int>(k+1, -1));
        return f(s, 0, n, k, mem);
    }
};

int main() {
    auto sol = Solution();
    string s; int k;
    // parameters init
    s = "abc", k = 2;
    OUT(sol.palindromePartition(s, k));
    s = "aabbc", k = 3;
    OUT(sol.palindromePartition(s, k));
    s = "daabbc", k = 1;
    OUT(sol.palindromePartition(s, k));
    s = "daabbc", k = 2;
    OUT(sol.palindromePartition(s, k));
    s = "daabbc", k = 3;
    OUT(sol.palindromePartition(s, k));
    s = "daabbc", k = 4;
    OUT(sol.palindromePartition(s, k));
    s = "leetcode", k = 4;
    OUT(sol.palindromePartition(s, k));
    s = "leetcode", k = 8;
    OUT(sol.palindromePartition(s, k));
    return 0;
}
