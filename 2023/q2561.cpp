#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
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
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> c1, ct, c_in, c_out;
        for (int x : basket1) c1[x]++;
        ct = c1;
        for (int x : basket2) ct[x]++;
        int mk = 1e9, d;
        for (auto [k, v] : ct) {
            mk = min(mk, k);
            if (v % 2 == 1) return -1;
            d = v/2 - c1[k];  // +代表缺，-代表多
            if (d > 0) c_in[k] = d;
            else if (d < 0) c_out[k] = -d;
        }
        if (c_in.empty()) return 0;
        vector<pair<int, int>> cv_in(c_in.begin(), c_in.end()), cv_out(c_out.begin(), c_out.end());
        sort(cv_in.begin(), cv_in.end());
        sort(cv_out.begin(), cv_out.end());
        int i=0, j, t=0, k;
        long long ans = 0;
        while (i < cv_in.size() && cv_in[i].first < 2*mk) {
            t += cv_in[i].second;
            k=cv_in[i].second, j=cv_out.size()-1;
            while (k>0) {
                if (cv_out[j].second > k) {
                    cv_out[j] = {cv_out[j].first, cv_out[j].second - k};
                    ans += 1ll * k * min(cv_in[i].first, cv_out[j].first);
                    k = 0;
                } else {
                    k -= cv_out[j].second;
                    ans += 1ll * cv_out[j].second * min(cv_in[i].first, cv_out[j].first);
                    cv_out.pop_back();
                    j--;
                }
            }
            i++;
        }
        i=0;
        while (i < cv_out.size() && cv_out[i].first < 2*mk) {
            t += cv_out[i].second;
            ans += 1ll * cv_out[i].second * cv_out[i].first;
            i++;
        }
        int s = 0;
        for (auto [kkk, v] : cv_in) s += v;
        ans += 2ll * (s-t) * mk;
        return ans;
    }
};

/*
a:1,b:2,d:-1,e:-5,c:3, 假设 e c 非常大， abd都很小 a+2b+d+2e
a:4,b:2,d:-1,e:-5, +3a,
a:4,b:2,d:-6, +3a+5d+4a+2b 有可能要反向操作

a:1, b:1, c:-1, d:-1
small:-1,a:1, b:1, c:-1
small:-2,a:1, b:1

min在A，A有多有少，A给出min，收回缺的，A拿回min，给出多的，总数*min
另一种，给出多的，换回少的，min(多，少)，次数少一半
若 2*min < min(多，少)

min不在A，A有多有少，A拿min，给出多的，A给出min，收回缺的，总数*min

若不能取巧，
100, +101,+102,-112,+113,-114,-114,-114,+118,-119,+120
112] +101,+102,+113,-114,-114,-114,+118,-119,
112, 101] +102,+113,-114,-114,-114,+118,
112, 101, 114] +102,+113,-114,-114


55, +101,+102,-112,+113,-114,-114,-114,+118,-119,+120
*/

int main() {
    auto sol = Solution();
    // parameters init
    vector<int> b1, b2;
    b1 = {4,2,2,2}, b2 = {1,4,1,2};
    std::cout << sol.minCost(b1, b2) << std::endl;
    b1 = {2,3,4,1}, b2 = {3,2,5,1};
    std::cout << sol.minCost(b1, b2) << std::endl;
    b1 = {1,1,100,100}, b2 = {2,2,200,200};
    std::cout << sol.minCost(b1, b2) << std::endl;
    b1 = {1,100,100}, b2 = {1,200,200};
    std::cout << sol.minCost(b1, b2) << std::endl;
    b1 = {4,4,4,4,3}, b2 = {5,5,5,5,3};
    std::cout << sol.minCost(b1, b2) << std::endl;
    return 0;
}
