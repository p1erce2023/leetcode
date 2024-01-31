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
    vector<vector<int>> getSkyline(vector<vector<int>>& B) {
        vector<vector<int>> ans={{-1,0}};
        vector<pair<int,int>> arr;
        int le,ri,h,i=0,pos;
        for (auto& bd : B) {
            le=bd[0],ri=bd[1],h=bd[2];
            arr.push_back({le,h});
            arr.push_back({ri,-h});
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        pq.push(0);
        unordered_map<int,int> to_del;
        while (i<arr.size()) {
            pos = arr[i].first;
            while (i<arr.size() && arr[i].first == pos) {
                if (arr[i].second < 0) {
                    h = -arr[i].second;
                    if (pq.top() == h) {
                        pq.pop();
                        while (to_del.count(pq.top())) {
                            h = pq.top();
                            to_del[h]--;
                            if (to_del[h]==0) to_del.erase(h);
                            pq.pop();
                        }
                    } else to_del[h]++;
                } else {
                    pq.push(arr[i].second);
                }
                ++i;
            }
            if (pq.top() != ans.back()[1])
                ans.push_back({pos,pq.top()});
        }
        ans.erase(ans.begin());
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> buildings;
    buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    auto vvv = sol.getSkyline(buildings);
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
