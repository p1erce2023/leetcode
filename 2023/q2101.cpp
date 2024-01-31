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
    int dfs(int i, vector<vector<int>>& e) {
        int n=e.size(), x, c=1;
        vector<int> seen(n, 0), q={i};
        seen[i] = 1;
        while (!q.empty()) {
            x = q.back();
            q.pop_back();
            for (int nx : e[x]) {
                if (!seen[nx]) {
                    seen[nx] = 1;
                    q.push_back(nx);
                    ++c;
                }
            }
        }
        return c;
    }
    int maximumDetonation(vector<vector<int>>& A) {
        int n=A.size(), ans=0, dx, dy;
        // directed graph
        vector<vector<int>> e(n, vector<int>());
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                dx=A[i][0]-A[j][0],dy=A[i][1]-A[j][1];
                if (dx*dx+dy*dy<=A[i][2]*A[i][2])
                    e[i].push_back(j);
                if (dx*dx+dy*dy<=A[j][2]*A[j][2])
                    e[j].push_back(i);
            }
        }
        for (int i=0; i<n; i++)
            ans = max(ans, dfs(i, e));
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> bombs;
    bombs = {{855,82,158},{17,719,430},{90,756,164},{376,17,340},{691,636,152},{565,776,5},{464,154,271},{53,361,162},{278,609,82},{202,927,219},{542,865,377},{330,402,270},{720,199,10},{986,697,443},{471,296,69},{393,81,404},{127,405,177}};
    OUT(sol.maximumDetonation(bombs));
    return 0;
}
