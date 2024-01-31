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
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& T) {

    }
        
    vector<int> f(int x, int p, vector<vector<int>>& e, vector<string>& v) {
        vector<int> ans={x};
        vector<vector<int>> paths;
        while (!e[x].empty()) {
            int y = e[x].back();
            e[x].pop_back();
            paths.push_back(f(y, x, e, v));
        }
        if (paths.size() > 1) {
            sort(paths.begin(), paths.end(), [&x, &v](auto& a, auto& b) {
                if (a.back()==x) {
                    if (b.back()==x)
                        return v[a[0]] < v[b[0]];
                    else 
                        return true;
                } else 
                    return false;
            });
        }
        for (auto& p : paths) {
            for (auto& s : p)
                ans.push_back(s);
        }
        return ans;
    }
    vector<string> findItinerary2(vector<vector<string>>& T) {
        unordered_map<string, int> mp;
        vector<string> v;
        vector<vector<int>> e(601);
        for (auto& ee : T) {
            int a, b;
            if (!mp.count(ee[0])) {
                mp[ee[0]] = v.size();
                v.push_back(ee[0]);
            }
            if (!mp.count(ee[1])) {
                mp[ee[1]] = v.size();
                v.push_back(ee[1]);
            }
            a = mp[ee[0]], b = mp[ee[1]];
            e[a].push_back(b);
        }
        for (auto& vv : e)
            sort(vv.begin(), vv.end(), [&v](int i, int j) {
                return v[i] > v[j];
            });
        auto res = f(mp["JFK"], -1, e, v);
        vector<string> ans(res.size());
        for (int i=0; i<res.size(); ++i)
            ans[i] = v[res[i]];
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<string>> T;
    T = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    for (auto vi : sol.findItinerary2(T)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    T = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    for (auto vi : sol.findItinerary2(T)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
