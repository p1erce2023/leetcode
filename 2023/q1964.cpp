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
    void update(vector<int>& v, int k, int m, int vv) {
        for (int i=k+1; i<=m; i+=(i&-i))
            v[i] = max(v[i], vv);
    }
    int query(vector<int>& v, int k) {
        int ans=v[k+1];
        for (int i=k+1; i; i-=(i&-i))
            ans=max(ans,v[i]);
        return ans;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        // transform A(range from 1~1e7) to AA(range from 0~n)
        int n=A.size(), m, qres;
        vector<int> B(A), AA(n);
        sort(B.begin(), B.end());
        B.erase(std::unique(B.begin(), B.end()), B.end());
        m = B.size();
        unordered_map<int, int> d;
        for (int i=0; i<m; i++) d[B[i]] = i;
        for (int i=0; i<n; i++) AA[i] = d[A[i]];
        vector<int> f(m+1);
        // fenwick max can be used on [0,m)
        update(f, AA[0], m, 1);
        vector<int> ans(n,1);
        for (int i=1; i<n; i++) {
            qres = query(f, AA[i]);
            ans[i] = qres+1;
            update(f, AA[i], m, qres+1);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> obstacles;
    obstacles = {3,1,5,6,4,2};
    for (auto vi : sol.longestObstacleCourseAtEachPosition(obstacles)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    obstacles = {2,2,1};
    for (auto vi : sol.longestObstacleCourseAtEachPosition(obstacles)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    obstacles = {1,2,3,2};
    for (auto vi : sol.longestObstacleCourseAtEachPosition(obstacles)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    obstacles = {9,1,6,5,2,10,1,4,3,7,8,6,2,4,2,5,1,4,4,8};
    for (auto vi : sol.longestObstacleCourseAtEachPosition(obstacles)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
