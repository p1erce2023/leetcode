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
class MedianFinder {
public:
    priority_queue<int> lh;
    priority_queue<int, vector<int>, std::greater<>> rh;
    MedianFinder() {}

    void addNum(int x) {
        if (lh.empty())
            lh.push(x);
        else if (rh.empty()) {
            if (lh.top() <= x)
                rh.push(x);
            else {
                rh.push(lh.top());
                lh.pop();
                lh.push(x);
            }
        } else {
            if (x < lh.top()) {
                if (lh.size() != rh.size()) {
                    rh.push(lh.top());
                    lh.pop();
                }
                lh.push(x);
            } else if (x == lh.top()) {
                if (lh.size() == rh.size())
                    lh.push(x);
                else
                    rh.push(x);
            } else {
                if (lh.size() == rh.size()) {
                    if (x <= rh.top()) {
                        lh.push(x);
                    } else {
                        lh.push(rh.top());
                        rh.pop();
                        rh.push(x);
                    }
                } else {
                    rh.push(x);
                }
            }
        }
    }

    double findMedian() {
        if (lh.size() == rh.size())
            return (lh.top()+rh.top())/2.0;
        else
            return lh.top();
    }
};

int main() {

    // parameters init
    OUT(sol);
    return 0;
}
