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
    const int MOD=1e9+7;
    const int p[10]={0,0,1,1,0,1,0,1,0,0};
public:
    int f(int x, int n, int k, string& s, int minL, vector<vector<int>>& mem) {
        if (k==0)
            return x<=n? 1 : 0;
        else if (x>n-k*minL)
            return 0;
        if (mem[x][k] != -1) return mem[x][k];
        int ans = f(x+1, n, k, s, minL, mem);
        if (p[s[x]-'0'] && !p[s[x-1]-'0'])
            ans = (ans + f(x+minL, n, k-1, s, minL, mem)) % MOD;
        return mem[x][k] = ans;
    }
    int beautifulPartitions(string s, int k, int minL) {
        int n=s.size();
        if (!p[s[0]-'0'] || p[s[n-1]-'0']) return 0;
        if (k==1) return 1;
        minL = max(minL, 2);
        vector<vector<int>> mem(n, vector<int>(k, -1));
        return f(minL,n,k-1,s,minL,mem);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s; int k, minL;
    s = "23542185131", k = 3, minL = 2;
    OUT(sol.beautifulPartitions(s,k,minL));
    s = "23542185131", k = 3, minL = 3;
    OUT(sol.beautifulPartitions(s,k,minL));
    s = "3312958", k = 3, minL = 1;
    OUT(sol.beautifulPartitions(s,k,minL));
    s = "33129258", k = 3, minL = 1;
    OUT(sol.beautifulPartitions(s,k,minL));
    s = "33129", k = 3, minL = 1;
    OUT(sol.beautifulPartitions(s,k,minL));
    s = "3434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434343434", k = 1000, minL=1000;
    OUT(sol.beautifulPartitions(s,k,minL));
    return 0;
}
