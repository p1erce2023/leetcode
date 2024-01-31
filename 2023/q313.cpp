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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        using LL = long long;
        int m=primes.size();
        LL mi;
        vector<int> p(m,0), v(n);
        vector<LL> pp(m);
        v[0] = 1;
        for (int i=1; i<n; i++) {
            mi = 1ll*v[p[0]]*primes[0];
            for (int j=0; j<m; j++) {
                pp[j] = 1ll*v[p[j]]*primes[j];
                mi = min(mi, pp[j]);
            }
            v[i] = mi;
            for (int j=0; j<m; j++)
                if (pp[j] == mi)
                    p[j]++;
        }
        return v[n-1];
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n; vector<int> primes;
    n = 12, primes = {2,7,13,19};
    OUT(sol.nthSuperUglyNumber(n, primes));
    return 0;
}
