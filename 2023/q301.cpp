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
    bool f(const string& s) {
        int x=0;
        for (char c : s)
            if (c=='(') ++x;
            else if (c==')') {
                if (x) --x;
                else return false;
            }
        if (x) return false;
        else return true;
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> q={s}, nq;
        vector<string> ans;
        while (!q.empty()) {
            for (auto& ss : q)
                if (f(ss))
                    ans.push_back(ss);
            if (!ans.empty())
                return ans;
            for (auto& ss : q)
                for (int i=0; i<ss.size(); ++i)
                    if (ss[i]=='(' || ss[i]==')')
                        nq.insert(ss.substr(0,i) + ss.substr(i+1));
            q = std::move(nq);
        }
        return {};
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "()())()";
    for (auto vi : sol.removeInvalidParentheses(s)) { std::cout << vi << ", "; }
    std::cout << std::endl;
    s = "(a)())()";
    for (auto vi : sol.removeInvalidParentheses(s)) { std::cout << vi << ", "; }
    std::cout << std::endl;
    s = ")(";
    for (auto vi : sol.removeInvalidParentheses(s)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
