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
    int numberOfArrays(string s, int k) {
        int ksz = std::to_string(k).size(), n=s.size(), MOD=1e9+7;
        long long c;
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for (int i=n-1; i>-1; i--) {
            if (s[i]=='0') continue;
            c = 0;
            for (int j=i; j<min(i+ksz,n); j++) {
                c = c * 10 + (s[j]-'0');
                if (c <= k)
                    dp[i] = (dp[i] + dp[j+1]) % MOD;
            }
        }
        return dp[0];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s; int k;
    s = "1000", k = 10000;
    std::cout << sol.numberOfArrays(s,k) << std::endl;
    return 0;
}
