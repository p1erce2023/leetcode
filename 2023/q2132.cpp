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
    void myprint(vector<vector<int>>& mat) {
        std::cout << "myprint\n";
        for (auto& row : mat) {
            for (int x : row) std::cout << x << ' ';
            std::cout << std::endl;
        }
    }

    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> fb(n, vector<int>(m,0)), stamp(fb);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]) {
                    fb[i][j] += 1;
                    if (i-h>-1) fb[i-h][j] += -1;
                    if (j-w>-1) fb[i][j-w] += -1;
                    if (i-h>-1 && j-w>-1) fb[i-h][j-w] += 1;
                }
            }
        }
        // myprint(fb);
        // spread to mark forbid place, reversed order
        int s = 0;
        for (int j=m-1; j>-1; j--) {
            s += fb[n-1][j];
            fb[n-1][j] = s;
        }
        for (int i=n-2; i>-1; i--) {
            s = 0;
            for (int j=m-1; j>-1; j--) {
                s += fb[i][j];
                fb[i][j] = fb[i+1][j] + s;
            }
        }
        // myprint(fb);
        // mark stamp where possible
        for (int i=0; i<=n-h; i++) {
            for (int j=0; j<=m-w; j++) {
                if (fb[i][j]) continue;
                stamp[i][j] += 1;
                if (j+w<m) stamp[i][j+w] += -1;
                if (i+h<n) stamp[i+h][j] += -1;
                if (j+w<m && i+h<n) stamp[i+h][j+w] += 1;
            }
        }
        // myprint(stamp);
        // spread
        s = 0;
        for (int j=0; j<m; j++) {
            s += stamp[0][j];
            stamp[0][j] = s;
        }
        for (int i=1; i<n; i++) {
            s = 0;
            for (int j=0; j<m; j++) {
                s += stamp[i][j];
                stamp[i][j] = stamp[i-1][j] + s;
            }
        }
        // myprint(stamp);
        // check
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!stamp[i][j] && !grid[i][j]) return false;
            }
        }
        return true;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> grid; int stampHeight, stampWidth;
    grid = {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}}, stampHeight = 4, stampWidth = 3;
    std::cout << sol.possibleToStamp(grid, stampHeight, stampWidth) << std::endl;
    grid = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}, stampHeight = 2, stampWidth = 2;
    std::cout << sol.possibleToStamp(grid, stampHeight, stampWidth) << std::endl;
    return 0;
}

// 思路是类似的，别的实现可能是用 2d 区间和 prefix sum，来看哪些地方可以放 stamp，
// 跟我用 差分 直接把 不能放 stamp 的地方标记出来，是一个道理
// 但写出来真要点时间呐