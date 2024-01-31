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
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m=grid.size(),n=grid[0].size(),l1=0,l2=0,l3=0,l4=0;
        grid[i][j] = 0;
        if (i==0) l1 = -1;
        else if (grid[i-1][j]) l1 = dfs(grid,i-1,j);
        if (i==m-1) l2 = -1;
        else if (grid[i+1][j]) l2 = dfs(grid,i+1,j);
        if (j==0) l3 = -1;
        else if (grid[i][j-1]) l3 = dfs(grid,i,j-1);
        if (j==n-1) l4 = -1;
        else if (grid[i][j+1]) l4 = dfs(grid,i,j+1);
        if (l1 != -1 && l2 != -1  && l3 != -1  && l4 != -1)
            return 1+l1+l2+l3+l4;
        else
            return -1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, d;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]) {
                    d = dfs(grid, i, j);
                    if (d != -1) ans += d;
                }
            }
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> grid;
    grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    std::cout << sol.numEnclaves(grid) << std::endl;
    return 0;
}
