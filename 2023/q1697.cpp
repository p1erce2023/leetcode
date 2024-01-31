#include <algorithm>
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

// Standard Disjoint-set data structure implementation.
class DSU {
    vector<int> Parent, Rank;
    public:
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) return false;
        if (Rank[x] < Rank[y]) Rank[y] += Rank[x], Parent[x] = y;
        else Rank[x] += Rank[y], Parent[y] = x;
        return true;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool> ans(m);
        for (int i=0; i<m; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](auto& l, auto& r) {return l[2] < r[2];});
        sort(edgeList.begin(), edgeList.end(), [](auto& l, auto& r) {return l[2] < r[2];});
        auto dsu = DSU(n);
        int i=0, j=0, en=edgeList.size();
        for (auto& q : queries) {
            while (j < en && edgeList[j][2] < q[2]) {
                dsu.Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[q[3]] = (dsu.Find(q[0]) == dsu.Find(q[1]));
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int a=3,b=4,c=5,e=1,x=10;
    x += a == b;
    OUT(x);
    a += e;
    x += a == b;
    OUT(x);
    return 0;
}
