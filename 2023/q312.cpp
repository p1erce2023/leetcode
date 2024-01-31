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
using std::multiset;
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
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using UMPII = unordered_map<int,int>;
class Solution {
public:
    int mem[302][302];
    int f(int i, int j, vector<int>& A) {
        if (i>j) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int ans=0;
        for (int k=i; k<=j; ++k)
            ans = max(ans, A[i-1] * A[k] * A[j+1] + f(i, k-1, A) + f(k+1, j, A));
        return mem[i][j] = ans;
    }
    int maxCoins(vector<int>& A) {
        int n=A.size();
        A.insert(A.begin(),1);
        A.push_back(1);
        memset(mem, -1, sizeof(mem));
        return f(1,n,A);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VI nums;
    nums = {3,1,5,8};
    OUT(sol.maxCoins(nums));
    nums = {1,5};
    OUT(sol.maxCoins(nums));
    return 0;
}
