#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using std::priority_queue;
using std::vector;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // 逆向思维，时间 t 最多能修多少辆车
        // 二分查找，找到第一个满足条件的时间点即可
        /*
        背下来，二分查找模版
        保证 low 不可行，high 可行，取中点，若中点不可行，则 low = mid + 1，若中点可行，取 high = mid
        */
        /*
        long long low = 0, high = 1e14;
        while (low < high) {
            long long mid = low + (high - low) / 2, repaired_cars = 0;
            for (int& r: ranks)
                repaired_cars += sqrt(mid / r);
            if (repaired_cars < cars) low = mid + 1;
            else high = mid;
        }
        return low;
        */
    }

    long long repairCars2(vector<int>& ranks, int cars) {
        // 用优先级队列，把下一个最小的依次挪出
        // 对重复的rank进行频率统计，否则 TLE
        // 但时间复杂度很差
        vector<int> rep(ranks.size(), 0);
        auto cmp = [](pair<long long, int>& a, pair<long long, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> c;
        for (int i = 0; i < ranks.size(); i++) {
            if (c.find(ranks[i]) == c.end()) {
                pq.push({ranks[i] * (2 * rep[i] + 1), i});
                c[ranks[i]] = 1;
            } else {
                c[ranks[i]]++;
            }
        }
        int idx;
        long long t;
        while (cars > 0) {
            std::tie(t, idx) = pq.top();
            pq.pop();
            rep[idx]++;
            pq.push({t + ranks[idx] * (1 + 2 * rep[idx]), idx});
            cars -= c[ranks[idx]];
        }
        return t;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums = {4,2,3,1};
    std::cout << s.repairCars2(nums, 10) << ' ' << s.repairCars(nums, 10) << std::endl;
    nums = {5,1,8};
    std::cout << s.repairCars2(nums, 6) << ' ' << s.repairCars(nums, 6) << std::endl;
    return 0;
}