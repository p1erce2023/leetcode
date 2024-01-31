#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        std::sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        vector<int> t = ranges[0];
        int i = 1, c = 1;
        while (i < ranges.size()) {
            if (ranges[i][0] <= t[1]) {
                t[1] = max(t[1], ranges[i][1]);
            } else {
                c++;
                t = ranges[i];
            }
            i++;
        }
        // std::cout << c << '\n';
        int res = 1;
        const int MOD = 1e9+7;
        long long bn = static_cast<long long>(std::pow(10,9))+7;
        while (c != 0) {
            res = (res * 2) % bn;
            c--;
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    vector<vector<int> > ranges = {{6,10},{5,15}};
    std::cout << s.countWays(ranges) << std::endl;
    return 0;
}