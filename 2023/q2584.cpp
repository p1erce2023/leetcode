#include <iostream>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    int findValidSplit2(vector<int>& nums) {
        int idx = 0, n = nums.size(), j, k;
        for (int j = 0; j <= idx; j++) {
            for (int k = idx + 1; k < n; ) {
                if (nums[j] == 1 || nums[k] == 1 || std::gcd(nums[j], nums[k]) == 1) {
                    k++;
                } else {
                    idx = k;
                    k = idx + 1;
                    if (k == n) return -1;
                }
            }
        }
        return idx;
    }

    bool is_prime(int x, vector<int>& primes) {
        int c = sqrt(x);
        for (int p : primes) {
            if (p > c) return true;
            if (x % p == 0) return false;
        }
        return true;
    }

    vector<int> get_prime_factors(int x, const vector<int>& primes) {
        int c = x / 2;
        vector<int> ans;
        for (int p : primes) {
            if (p > c) break;
            if (x % p == 0) {
                ans.push_back(p);
                x = x / p;
                while (x % p == 0)
                    x = x / p;
                if (x == 1) break;
            }
        }
        if (x != 1) ans.push_back(x);
        return ans;
    }

    int findValidSplit(vector<int>& nums) {
        int idx = 0, n = nums.size();
        if (n == 1) return -1;
        if (nums[0] == 1) return 0;

        vector<int> primes = {2, 3};
        for (int i = 5; i < 1000; i+= 2) {
            if (is_prime(i, primes))
                primes.push_back(i);
        }

        unordered_set<int> l_factors, r_factors;
        vector<int> pf = get_prime_factors(nums[0], primes);
        l_factors = unordered_set<int>(pf.begin(), pf.end());
        bool expanded;
        for (int i = 1; i < n; i++) {
            expanded = false;
            pf = get_prime_factors(nums[i], primes);
            for (int k : pf) {
                if (l_factors.find(k) != l_factors.end()) {
                    idx = i;
                    if (idx == n - 1) return -1;
                    l_factors.insert(r_factors.begin(), r_factors.end());
                    l_factors.insert(pf.begin(), pf.end());
                    r_factors.clear();
                    expanded = true;
                    break;
                }
            }
            if (!expanded)
                r_factors.insert(pf.begin(), pf.end());
        }
        return idx;
    }

    int findValidSplit3(vector<int>& nums) {
        vector<int> primes = {2, 3};
        for (int i = 5; i < 1000; i+= 2) {
            if (is_prime(i, primes))
                primes.push_back(i);
        }
        vector<int> line(10001), pf;
        unordered_map<int, int> p_start_idx;
        for (int i = 0; i < nums.size(); i++) {
            pf = get_prime_factors(nums[i], primes);
            for (int p : pf) {
                if (p_start_idx.find(p) == p_start_idx.end())
                    p_start_idx[p] = i;
                line[p_start_idx[p]]++;
                line[i]--;
            }
        }
        std::partial_sum(line.begin(), line.end(), line.begin());
        int ans = std::find(line.begin(), line.end(), 0) - line.begin();
        return ans < nums.size() - 1? ans : -1;
    }
};

int main() {
    auto s = Solution();
    vector<int> v = {4,7,15,8,3,5};
    std::cout << s.findValidSplit(v) << ' ' << s.findValidSplit3(v) << std::endl;
    v = {4,7,8,15,3,5};
    std::cout << s.findValidSplit(v) << ' ' << s.findValidSplit3(v) << std::endl;
    v = {7,4,8,15,3,5};
    std::cout << s.findValidSplit(v) << ' ' << s.findValidSplit3(v) << std::endl;
    v = {15,4,8,3,5,7};
    std::cout << s.findValidSplit(v) << ' ' << s.findValidSplit3(v) << std::endl;
    v = {15,4,3,5,7,8};
    std::cout << s.findValidSplit(v) << ' ' << s.findValidSplit3(v) << std::endl;
    return 0;
}