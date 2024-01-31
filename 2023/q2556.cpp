#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::priority_queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, c=0;
        vector<vector<int>> s(m, vector<int>(n, 0));
        vector<pair<int, int>> q = {{0,0}};
        if ((m == 1 && n == 1) || (m == 1 && n == 2) || (m == 2 && n == 1)) return false;
        while (!q.empty()) {
            std::tie(i, j) = q.back();
            q.pop_back();
            if (i == m-1 && j == n-1) {
                c++;
                if (c == 1) {
                    q = {{0,0}};
                    continue;
                } else {
                    return false;
                }
            }
            s[i][j] = 1;
            if (i+1 < m && !s[i+1][j] && grid[i+1][j]) q.push_back({i+1, j});
            if (j+1 < n && !s[i][j+1] && grid[i][j+1]) q.push_back({i, j+1});
        }
        return true;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> grid;
    grid = {{1,1,1,0,0},{1,0,1,0,0},{1,1,1,1,1},{0,0,1,1,1},{0,0,1,1,1}};
    std::cout << sol.isPossibleToCutPath(grid) << std::endl;
    grid = {{1,1,1},{1,0,1},{1,1,1}};
    std::cout << sol.isPossibleToCutPath(grid) << std::endl;
    grid = {{1,1,1},{1,0,0},{1,1,1}};
    std::cout << sol.isPossibleToCutPath(grid) << std::endl;
    return 0;
}
