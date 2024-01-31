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
class Solution {
public:
    vector<string> f(LL y, LL m, int idx, string& s, int t) {
        vector<string> ans;
        LL x=0;
        int n=s.size(), i;
        for (i=idx; i<n-1; ++i) {
            x = x*10 + s[i] - '0';
            for (auto& res : f(y, x*m, i+1, s, t)) {
                string exp = s.substr(idx,i-idx+1);
                exp.push_back('*');
                exp.append(res);
                ans.push_back(exp);
            }
            for (auto& res : f(y+m*x, 1, i+1, s, t)) {
                string exp = s.substr(idx,i-idx+1);
                exp.push_back('+');
                exp.append(res);
                ans.push_back(exp);
            }
            for (auto& res : f(y+m*x, -1, i+1, s, t)) {
                string exp = s.substr(idx,i-idx+1);
                exp.push_back('-');
                exp.append(res);
                ans.push_back(exp);
            }
            if (x==0) return ans;
        }
        x = x*10 + s[i] - '0';
        if (y+m*x == t)
            ans.push_back(s.substr(idx));
        return ans;
    }
    vector<string> addOperators(string s, int t) {
        return f(0,1,0,s,t);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string num; int target;
    num = "1234", target = 46;
    std::cout << "ans:\n";
    for (auto vi : sol.addOperators(num, target)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    num = "123", target = 6;
    std::cout << "ans:\n";
    for (auto vi : sol.addOperators(num, target)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    num = "232", target = 8;
    std::cout << "ans:\n";
    for (auto vi : sol.addOperators(num, target)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    num = "3456237490", target = 9191;
    std::cout << "ans:\n";
    for (auto vi : sol.addOperators(num, target)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    num = "00", target = 0;
    std::cout << "ans:\n";
    for (auto vi : sol.addOperators(num, target)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    return 0;
}
