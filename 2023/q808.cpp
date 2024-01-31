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
using std::accumulate;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;

class Solution {
public:
    pair<double,double> f(int x, int y, unordered_map<int, unordered_map<int, pair<double, double>>>& dp) {
        if (x==0) {
            if (y==0) return {0, 1};
            else return {1,0};
        } else if (y==0) {
            return {0,0};
        } else {
            if (dp.count(x) && dp[x].count(y))
                return dp[x][y];
            double p1=0, p2=0;
            if (x <= 100) {
                p1 += 0.25;
            } else {
                auto [q1, q2] = f(x-100, y, dp);
                p1 += 0.25 * q1;
                p2 += 0.25 * q2;
            }
            if (x <= 75) {
                if (y > 25)
                    p1 += 0.25;
                else
                    p2 += 0.25;
            } else if (y > 25) {
                auto [q1, q2] = f(x-75, y-25, dp);
                p1 += 0.25 * q1;
                p2 += 0.25 * q2;
            }
            if (x <= 50) {
                if (y > 50)
                    p1 += 0.25;
                else
                    p2 += 0.25;
            } else if (y > 50) {
                auto [q1, q2] = f(x-50, y-50, dp);
                p1 += 0.25 * q1;
                p2 += 0.25 * q2;
            }
            if (x <= 25) {
                if (y > 75)
                    p1 += 0.25;
                else
                    p2 += 0.25;
            } else if (y > 75) {
                auto [q1, q2] = f(x-25, y-75, dp);
                p1 += 0.25 * q1;
                p2 += 0.25 * q2;
            }
            return dp[x][y] = {p1, p2};
        }
    }
    double soupServings(int n) {
        if (n>5000) return 1;
        unordered_map<int, unordered_map<int, pair<double, double>>> dp;
        auto [p1, p2] = f(n, n, dp);
        return p1 + p2 * 0.5;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int n;
    n = 50;
    OUT(sol.soupServings(n));
    n = 100;
    OUT(sol.soupServings(n));
    n = 1000;
    OUT(sol.soupServings(n));
    n = 5000;
    OUT(sol.soupServings(n));
    return 0;
}
