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
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n) return 0;
        vector<long long> d(n-1,0);
        for (int i=0; i<n-1; i++) {
            d[i] = weights[i] + weights[i+1];
        }
        sort(d.begin(), d.end());
        long long ans=0;
        for (int i=0; i<k-1; i++) {
            ans += d[n-2-i] - d[i];
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> weights; int k;
    weights = {1,4,2,5,2}, k = 3;
    std::cout << sol.putMarbles(weights, k) << std::endl;
    return 0;
}
