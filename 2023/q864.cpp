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
struct State {
    int x, y, k, mv;
    State() {
        k=0, mv=0;
    }
};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& M) {
        vector<State> q, nq;
        int m=M.size(), n=M[0].size(), ci, cj, ks=0;
        char c;
        vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        int dp[30][30][64];
        memset(dp,0,sizeof(dp));
        State starter;
        for (int i=0; i<M.size(); ++i)
            for (int j=0; j<M[0].size(); ++j)
                if (M[i][j]=='@') {
                    starter.x = i, starter.y = j;
                    M[i][j] = '.';
                } else if (M[i][j]<='z' && M[i][j]>='a')
                    ++ks;
        ks = (1<<ks) - 1;
        q.push_back(std::move(starter));
        while (!q.empty()) {
            for (auto& st : q) {
                for (auto [di,dj] : dirs) {
                    ci=di+st.x, cj=dj+st.y;
                    if (ci<0 || ci==m || cj<0 || cj==n) continue;
                    c = M[ci][cj];
                    if (c=='#') continue;
                    State nst(st);
                    nst.x=ci, nst.y=cj;
                    ++nst.mv;
                    if (c=='.') {
                        if (!dp[ci][cj][nst.k]) {
                            dp[ci][cj][nst.k] = 1;
                            nq.push_back(std::move(nst));
                        }
                    } else if (c>='a' && c<='z') {
                        nst.k |= 1<<(c-'a');
                        if (nst.k == ks)
                            return nst.mv;  // 本质上是 bfs，因此第一次遇到时就已经是最优
                        else if (!dp[ci][cj][nst.k]) {
                            dp[ci][cj][nst.k] = 1;
                            nq.push_back(std::move(nst));
                        }
                    } else if (c>='A' && c<='Z') {
                        if ((st.k & (1<<(c-'A'))) && dp[ci][cj][nst.k] == 0) {
                            dp[ci][cj][nst.k] = 1;
                            nq.push_back(std::move(nst));
                        }
                    }
                }
            }
            q = std::move(nq);
        }
        return -1;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> grid;
    grid = {"@.a..","###.#","b.A.B"};
    OUT(sol.shortestPathAllKeys(grid));
    grid = {"@..aA","..B#.","....b"};
    OUT(sol.shortestPathAllKeys(grid));
    grid = {"@Aa"};
    OUT(sol.shortestPathAllKeys(grid));
    return 0;
}
