#include <vector>
#include <unordered_set>
#include <iostream>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int findMinimumTime_WrongGreedy(vector<vector<int>>& tasks) {
        std::cout << "method1\n";
        using vset = vector<unordered_set<int> >;
        vset cnt(2001, unordered_set<int>());
        for (size_t i = 0; i < tasks.size(); i++) {
            for (int j = tasks[i][0]; j <= tasks[i][1]; j++) {
                cnt[j].insert(i);
            }
        }
        int r = 0;
        vector<int> indice;
        while (true) {
            int idx_with_largest_cnt;
            size_t largest_cnt = 0;
            for (size_t i = 1; i < 2001; i++) {
                if (cnt[i].size() >= largest_cnt) {
                    largest_cnt = cnt[i].size();
                    idx_with_largest_cnt = i;
                }
            }
            if (largest_cnt == 0) break;
            indice.push_back(idx_with_largest_cnt);
            r++;
            for (auto idx : cnt[idx_with_largest_cnt]) {
                tasks[idx][2] -= 1;
                if (tasks[idx][2] == 0) {
                    for (int i = tasks[idx][0]; i <= tasks[idx][1]; i++) {
                        if (i == idx_with_largest_cnt) continue;
                        cnt[i].erase(idx);
                    }
                }
            }
            cnt[idx_with_largest_cnt].clear();
        }
        std::sort(indice.begin(), indice.end());
        for (auto i : indice)
            std::cout << i << ' ';
        std::cout << std::endl;
        return r;
    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        int res = 0;
        std::sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        vector<bool> s(2001, false);
        for (auto& task : tasks) {
            int st = task[0], ed = task[1], dur = task[2], already_open = 0;
            for (int i = ed; i >= st; i--) {
                if (s[i]) already_open++;
            }
            while (already_open < dur) {
                if (!s[ed]) {
                    s[ed] = true;
                    res++;
                    already_open++;
                }
                ed--;
            }
        }
        return res;
    }
};



int main() {
    auto s = Solution();
    vector<vector<int> > tasks = {{2,3,1}, {4,5,1}, {1,5,2}};
    // std::cout << s.findMinimumTime(tasks) << std::endl;
    // tasks = {{1,3,2}, {2,5,3}, {5,6,2}};
    // std::cout << s.findMinimumTime(tasks) << std::endl;
    // tasks = {{1,3,2}, {2,5,3}, {5,6,2}, {1000,1000,1}, {1000,1001,2}, {1000,1003,2}};
    // std::cout << s.findMinimumTime(tasks) << std::endl;
    tasks = {{1,4,4},{5,6,2},{1,9,4},{2,12,7},{8,16,3},{12,22,5}};
    std::cout << s.findMinimumTime(tasks) << std::endl;
    tasks = {{1,4,4},{5,6,2},{1,9,4},{2,12,7},{8,16,3},{12,22,5}};
    std::cout << s.findMinimumTime_WrongGreedy(tasks) << std::endl;
    return 0;
}