#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using std::vector;
using std::tuple;
using std::priority_queue;
using std::pair;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // using node = tuple<int, int, int>;
        // auto cmp = [](node& l, node& r) {
        //     return std::get<0>(l) > std::get<0>(r);
        // };
        priority_queue<vector<int>, vector<vector<int>>, std::greater<>> pq;
        vector<vector<int>> xxx, yyy;
        pq.push({0, 0, 0});
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
        bool wait;
        while (!pq.empty()) {
            int t, x, y, ttt, nx, ny;
            auto& item = pq.top();
            t = item[0], x = item[1], y = item[2];
            pq.pop();
            if (x == m - 1 && y == n - 1) return t;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            xxx.clear();
            yyy.clear();
            for (auto [dx, dy] : directions) {
                nx = dx + x;
                ny = dy + y;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                    continue;
                wait = (grid[nx][ny] - t) % 2 == 0;
                ttt = std::max(grid[nx][ny] + wait, t + 1);
                xxx.push_back({ttt, nx, ny});
            }
            if (x + 1 < m && !visited[x+1][y]) {
                bool wait = (grid[x+1][y] - t) % 2 == 0;
                ttt = std::max(grid[x+1][y] + wait, t + 1);
                pq.push({ttt, x+1, y});
                yyy.push_back({ttt, x+1, y});
            }
            // 搞了半天，找代码的bug，最后发现是这两行的边界条件，写成了 x > 1
            if (x >= 1 && !visited[x-1][y]) {
                bool wait = (grid[x-1][y] - t) % 2 == 0;
                ttt = std::max(grid[x-1][y] + wait, t + 1);
                pq.push({ttt, x-1, y});
                yyy.push_back({ttt, x-1, y});
            }
            if (y + 1 < n && !visited[x][y+1]) {
                bool wait = (grid[x][y+1] - t) % 2 == 0;
                ttt = std::max(grid[x][y+1] + wait, t + 1);
                pq.push({ttt, x, y+1});
                yyy.push_back({ttt, x, y+1});
            }
            // 这里写成了 y > 1
            if (y >= 1 && !visited[x][y-1]) {
                bool wait = (grid[x][y-1] - t) % 2 == 0;
                ttt = std::max(grid[x][y-1] + wait, t + 1);
                pq.push({ttt, x, y-1});
                yyy.push_back({ttt, x, y-1});
            }
            std::sort(xxx.begin(), xxx.end());
            std::sort(yyy.begin(), yyy.end());
            if (xxx != yyy) {
                std::cout << x << ' ' << y << std::endl;
            }
        }
        return -1;
    }

    int minimumTime2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, std::greater<>> pq;
        pq.push({0, 0, 0}); // (t, r, c)
        while (!pq.empty()) {
            auto cur = pq.top();
            int t = cur[0], r = cur[1], c = cur[2];
            pq.pop();
            if (r == m - 1 && c == n - 1) {
                return t;
            }
            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;
            for (const auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
                    continue;
                }
                bool wait = (grid[nr][nc] - t) % 2 == 0;
                int nt = std::max(grid[nr][nc] + wait, t + 1);
                pq.push({nt, nr, nc});
            }
        }
        return -1;
    }
};

int main() {
    auto s = Solution();
    vector<vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    std::cout << s.minimumTime(grid) << ' ' << s.minimumTime2(grid) << std::endl;
    // grid = {{0,1,19918,17532,73994},{1,64846,11660,81193,21818},{22697,96349,33620,21978,35872},{45606,10606,47438,10590,87951},{42172,6610,53317,53397,8258},{70755,18132,24647,6589,26595},{95935,69808,57382,77103,86911},{69470,1890,40171,63178,28757},{81991,54413,50091,71739,23922},{56439,96824,65274,36359,8014},{39208,77984,81466,83276,99680},{47788,50458,32750,80948,27782},{79863,83612,56178,53709,11838},{4980,92014,69952,63460,11814},{57521,17011,96190,67073,50308},{96760,51950,51802,60779,75968},{14867,14709,14904,11151,56958},{51561,86397,85301,21794,94221},{69633,89153,57417,24669,27587},{67267,97543,46291,38609,17009},{73806,6892,39650,57590,9756},{97378,31584,51247,26487,63172},{26695,10726,41363,28627,47184},{45,55774,92171,76688,18184},{79328,20992,6796,43287,45016},{40846,31880,28816,45167,67387},{56246,98406,18229,11812,31536},{73329,64462,72660,34722,37768},{77723,13439,25453,61989,74519},{40535,46067,37713,2575,54428},{96960,49164,32529,77738,3094},{58190,90903,83463,63760,95313},{98837,54085,18374,8499,38229},{13347,6199,4345,37873,66273},{34168,7726,78083,37708,14736},{25974,78044,53371,97400,97506},{21610,84219,28256,78713,61405},{51348,29061,64794,80519,87016},{64615,75492,16815,60057,99211},{8536,40081,54203,45837,13569},{48194,49658,39361,9952,65630},{75053,75133,21747,37752,76920},{63504,30192,74992,86787,58734},{29613,41134,86397,5435,100000},{14848,14326,4965,46965,57542},{82712,816,93352,24396,19030},{79927,82798,13882,89595,90935},{42768,98631,2116,21047,7241},{42312,73044,74309,6824,618},{76383,90818,72150,36391,57268},{10503,5130,23276,57262,5601},{42867,66007,32771,9403,84066},{17959,21174,53612,38172,15944},{43128,90626,85927,55572,6425},{88909,54565,20709,60461,47926},{64203,50994,93942,84913,76843},{31121,42509,74690,16696,9109},{10116,44958,7436,62674,91080},{55566,92270,42083,69055,91953},{93302,24424,34540,28475,1373},{5639,39959,10324,31050,66744},{20637,64101,73129,51430,27225},{10430,13677,21385,97824,30760},{77323,92659,7937,9877,61466},{84867,26888,81632,26835,5843},{41649,17117,25092,42913,35431},{80972,69484,66589,4953,25449},{37072,68672,97026,48637,14218},{78592,77874,35575,26642,20030},{79468,52724,52145,8299,6079},{66149,58860,97894,68762,35883},{38509,52288,71659,75324,75832},{5950,59844,76613,77533,81260},{80640,61038,87676,35914,26811},{25383,88563,69573,50003,96750},{81487,86938,34986,40669,84106},{42670,27441,66674,83368,21417},{73815,54661,47483,72459,96939},{69747,78670,13778,83055,74236},{14043,20582,8266,32542,64894},{18366,26933,25812,93414,67986},{92739,17295,5389,32644,11588},{96483,49084,37475,51599,24695},{58463,1712,94614,49156,58975},{7608,50590,42137,34803,28001},{54352,60149,60848,85181,73677},{24484,32768,2306,7319,38348},{97895,30804,37521,97222,99550},{66379,63094,48776,69614,16112},{26999,91092,21418,10716,10492}};
    // std::cout << s.minimumTime(grid) << ' ' << s.minimumTime2(grid) << std::endl;
    return 0;
}