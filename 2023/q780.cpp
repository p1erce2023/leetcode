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
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (1) {
            if (sx==tx && sy==ty) return true;
            else if (sx!=tx && sy!=ty) {
                if (tx<sx||ty<sy) return false;
                if (tx < ty) {
                    ty -= tx;
                } else if (tx > ty) {
                    tx -= ty;
                } else return false;
            } else {
                if (sx==tx) {
                    if (ty>sy && (ty-sy)%sx==0) return true;
                    else return false;
                } else { // sy==ty
                    if (tx>sx && (tx-sx)%sy==0) return true;
                    else return false;
                }
            }
        }
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int sx,sy,tx,ty;
    sx = 1, sy = 1, tx = 3, ty = 5;
    OUT(sol.reachingPoints(sx,sy,tx,ty));
    sx = 1, sy = 1, tx = 2, ty = 2;
    OUT(sol.reachingPoints(sx,sy,tx,ty));
    sx = 1, sy = 1, tx = 1, ty = 1;
    OUT(sol.reachingPoints(sx,sy,tx,ty));
    return 0;
}
