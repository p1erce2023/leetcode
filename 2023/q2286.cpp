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
using VI = vector<int>;
using VVI = vector<vector<int>>;
using UMPII = unordered_map<int,int>;

class SegmentTree {
public:
    int n;
    vector<int> maxtree, sumtree;
    SegmentTree(int n_) : n(n_) {
        int sz = (int)(ceil(log2(n)));
        sz = (2 * pow(2, sz)) - 1;
        maxtree.resize(sz);
        sumtree.resize(sz);
    }

    int query_max(int l, int r) { return query_max_util(0, l, r, 0, n - 1); }
    int query_sum(int l, int r) { return query_sum_util(0, l, r, 0, n - 1); }

    int query_max_util(int i, int qL, int qR, int l, int r) {
        if (l >= qL && r <= qR)
            return maxtree[i];
        if (l > qR || r < qL)
            return INT_MIN;

        int m = (l + r) / 2;
        return max(query_util(2 * i + 1, qL, qR, l, m),
                    query_util(2 * i + 2, qL, qR, m + 1, r));
    }

    int query_sum_util(int i, int qL, int qR, int l, int r) {
        if (l >= qL && r <= qR)
            return maxtree[i];
        if (l > qR || r < qL)
            return INT_MIN;

        int m = (l + r) / 2;
        return max(query_util(2 * i + 1, qL, qR, l, m),
                    query_util(2 * i + 2, qL, qR, m + 1, r));
    }

    void update(int i, int val) {
        update_max_util(0, 0, n - 1, i, val);
        update_sum_util(0, 0, n - 1, i, val);
    }

    void update_max_util(int i, int l, int r, int pos, int val) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            maxtree[i] = max(val, maxtree[i]);
            return;
        }

        int m = (l + r) / 2;
        update_max_util(2 * i + 1, l, m, pos, val);
        update_max_util(2 * i + 2, m + 1, r, pos, val);
        maxtree[i] = max(maxtree[2 * i + 1], maxtree[2 * i + 2]);
    }
    void update_sum_util(int i, int l, int r, int pos, int val) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            maxtree[i] = max(val, maxtree[i]);
            return;
        }

        int m = (l + r) / 2;
        update_max_util(2 * i + 1, l, m, pos, val);
        update_max_util(2 * i + 2, m + 1, r, pos, val);
        maxtree[i] = max(maxtree[2 * i + 1], maxtree[2 * i + 2]);
    }
};
class BookMyShow {
public:
    BookMyShow(int n, int m) {

    }

    vector<int> gather(int k, int maxRow) {

    }

    bool scatter(int k, int maxRow) {

    }
};

int main() {
    // parameters init
    // BookMyShow* obj = new BookMyShow(2, 5);
    // for (auto vi : obj->gather(4,0)) { std::cout << vi << ' '; }
    // std::cout << std::endl;
    // for (auto vi : obj->gather(2,0)) { std::cout << vi << ' '; }
    // std::cout << std::endl;
    // OUT(obj->scatter(5,1));
    // OUT(obj->scatter(5,1));
    // BookMyShow* obj = new BookMyShow(5, 10);
    // OUT(obj->scatter(9,1));
    // OUT(obj->scatter(1,3));
    // for (auto vi : obj->gather(3,4)) { std::cout << vi << ' '; }
    // std::cout << std::endl;
    // for (auto vi : obj->gather(1,1)) { std::cout << vi << ' '; }
    // std::cout << std::endl;
    // for (auto vi : obj->gather(10,4)) { std::cout << vi << ' '; }
    // std::cout << std::endl;
    BookMyShow* obj = new BookMyShow(25, 941);
    for (auto vi : obj->gather(34,1)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : obj->gather(296,21)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : obj->gather(927,18)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : obj->gather(695,15)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : obj->gather(830,22)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : obj->gather(638,2)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    for (auto vi : obj->gather(169,15)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
