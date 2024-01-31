#include <vector>
#include <unordered_map>
#include <iostream>
using std::vector;
using std::unordered_map;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int waysToReachTarget2(int target, vector<vector<int>>& types, int m) {
        if (target == 0)
            return 1;
        int count = types[m][0], marks = types[m][1];
        if (m == 0) {
            if (target % marks != 0 || count * marks < target)
                return 0;
            else
                return 1;
        }
        int ans = 0;
        int k = target / marks;
        k = std::min(k, count);
        for (int i = 0; i <= k; i++) {
            ans += waysToReachTarget2(target - i * marks, types, m - 1) % MOD;
        }
        return ans;
    }

    int waysToReachTarget2(int target, vector<vector<int>>& types) {
        return waysToReachTarget2(target, types, types.size() - 1);
    }  // 还是有大量重复，所以 TLE

    unordered_map<int64_t, int> mem;
    int waysToReachTarget3(int target, vector<vector<int>>& types, int m) {
        if (target == 0)
            return 1;
        // unordered_map does not contain a hash function for a pair like it has for int, string, etc
        int64_t mk = target;
        mk = mk << 32;
        mk |= m;
        auto it = mem.find(mk);
        if (it != mem.end()) return it->second;
        int count = types[m][0], marks = types[m][1];
        if (m == 0) {
            if (target % marks != 0 || count * marks < target)
                return 0;
            else
                return 1;
        }
        int ans = 0;
        int k = target / marks;
        k = std::min(k, count);
        for (int i = 0; i <= k; i++) {
            ans = (0ll + ans + waysToReachTarget3(target - i * marks, types, m - 1)) % MOD;
        }
        mem[mk] = ans;
        return ans;
    }

    int waysToReachTarget3(int target, vector<vector<int>>& types) {
        return waysToReachTarget3(target, types, types.size() - 1);
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        int idx;
        for (auto& t : types) {
            vector<int> ndp(dp);
            for (int k = 0; k <= target; k++) {
                for (int i = 1; i <= t[0]; i++) {
                    idx = k + i * t[1];
                    if (idx > target) break;
                    ndp[idx] = (0ll + ndp[idx] + dp[k]) % MOD;
                }
            }
            std::swap(dp, ndp);
        }
        return dp[target];
    }
};

int main() {
    auto s = Solution();
    vector<vector<int>> types = {{6,1},{3,2},{2,3}};
    std::cout << s.waysToReachTarget2(18, types) << ' ' << s.waysToReachTarget(18, types) << std::endl;
    return 0;
}