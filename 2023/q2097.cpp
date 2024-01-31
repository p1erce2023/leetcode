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
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    void dfs(int x, unordered_map<int, vector<int>>& e, vector<vector<int>>& ans) {
        if (!e.count(x)) return;
        int y;
        while (!e[x].empty()) {
            y = e[x].back();
            e[x].pop_back();
            dfs(y, e, ans);
            ans.push_back({x,y});
        }
        e.erase(x);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> e;
        unordered_map<int,int> dg;
        for (auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            dg[ee[0]]++;
            dg[ee[1]]--;
        }
        int x;
        for (auto [k, v] : dg)
            if (v > 0) {
                x = k;
                break;
            }
        vector<vector<int>> ans;
        dfs(x, e, ans);
        while (!e.empty()) {
            x = e.begin()->first;
            dfs(x, e, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    VVI pairs;
    // pairs = {{1,2},{1,3},{2,1}};
    // auto vvv = sol.validArrangement(pairs);
    // std::cout << '[';
    // for (int ii=0; ii<vvv.size()-1; ii++) {
    //     std::cout << '[';
    //     for (int jj=0; jj<vvv[ii].size()-1; jj++)
    //         std::cout << vvv[ii][jj] << ',';
    //     std::cout << vvv[ii].back() << "],";
    // }
    // std::cout << '[';
    // for (int jj=0; jj<vvv.back().size()-1; jj++)
    //     std::cout << vvv.back()[jj] << ',';
    // std::cout << vvv.back().back() << ']';
    // std::cout << ']' << std::endl;

    pairs = {{8,5},{8,7},{0,8},{0,5},{7,0},{5,0},{0,7},{8,0},{7,8}};
    auto vvv = sol.validArrangement(pairs);
    std::cout << '[';
    for (int ii=0; ii<vvv.size()-1; ii++) {
        std::cout << '[';
        for (int jj=0; jj<vvv[ii].size()-1; jj++)
            std::cout << vvv[ii][jj] << ',';
        std::cout << vvv[ii].back() << "],";
    }
    std::cout << '[';
    for (int jj=0; jj<vvv.back().size()-1; jj++)
        std::cout << vvv.back()[jj] << ',';
    std::cout << vvv.back().back() << ']';
    std::cout << ']' << std::endl;
    return 0;
}
