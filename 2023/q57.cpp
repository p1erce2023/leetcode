#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::map;
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
    int bisect(int target, vector<vector<int>>& intervals) {
        int n=intervals.size(),i=0,j=n-1,mid,ans;
        if (target <= intervals[0][0]) return 0;
        else if (target > intervals[j][0]) return n;
        while (i < j) {
            mid = (i+j)/2;
            if (target > intervals[mid][0]) i = mid+1;
            else j=mid;
        }
        return i;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(),st,ed,left,right;
        if (n==0) return {newInterval};
        st = bisect(newInterval[0], intervals);
        ed = bisect(newInterval[1], intervals);
        vector<vector<int>> ans;
        ans.reserve(n);
        if (st == 0) {
            left = newInterval[0];
        } else if (intervals[st-1][1] >= newInterval[0]) {
            for (int i=0;i<st-1;i++) ans.push_back(intervals[i]);
            left = intervals[st-1][0];
        } else {
            for (int i=0;i<st;i++) ans.push_back(intervals[i]);
            left = newInterval[0];
        }
        if (ed == n) {
            right = max(intervals[n-1][1], newInterval[1]);
            ans.push_back({left, right});
        } else if (intervals[ed][0] == newInterval[1]) {
            right = intervals[ed][1];
            ans.push_back({left, right});
            for (int i=ed+1;i<n;i++) ans.push_back(intervals[i]);
        } else if (ed && intervals[ed-1][1] >= newInterval[1]) {
            right = intervals[ed-1][1];
            ans.push_back({left, right});
            for (int i=ed;i<n;i++) ans.push_back(intervals[i]);
        } else {
            right = newInterval[1];
            ans.push_back({left, right});
            for (int i=ed;i<n;i++) ans.push_back(intervals[i]);
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> intervals; vector<int> newInterval;
    intervals = {{1,5}}, newInterval = {2,3};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}}, newInterval = {1,3};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}}, newInterval = {0,1};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}}, newInterval = {-1,0};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}}, newInterval = {5,7};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}}, newInterval = {6,8};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}}, newInterval = {-1,8};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}, {7,10}}, newInterval = {0,20};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}, {7,10}}, newInterval = {0,8};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}, {7,10}}, newInterval = {2,8};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{1,5}, {7,10}}, newInterval = {2,20};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;
    intervals = {{2,4},{5,7},{8,10},{11,13}}, newInterval = {3,6};
    for (auto& item : sol.insert(intervals, newInterval)) {
        for (auto& v : item) std::cout << v << ' ';
        std::cout << "// ";
    }
    std::cout << std::endl;

    return 0;
}
