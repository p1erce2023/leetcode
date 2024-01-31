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
    int lastStoneWeightII(vector<int>& A) {
        int s=0,n=A.size();
        for (int x : A) s+=x;
        int c=s/2;
        vector<bool> dp(c+1);
        dp[0] = true;
        for (int x : A) {
            for (int i=c-x; i>=0; i--) {
                if (dp[i]) dp[i+x] = true;
            }
        }
        for (int j=c; j>-1; j--) if (dp[j]) return s-2*j;
        return -1;
    }
};


int main() {
    auto sol = Solution();
    // parameters init
    vector<int> arr;
    arr = {31,26,33,21,40};
    std::cout << sol.lastStoneWeightII(arr) << std::endl;
    return 0;
}
