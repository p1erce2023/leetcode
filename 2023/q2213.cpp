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
using std::accumulate;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qidx) {
        s.insert(s.begin(), '#');
        s.push_back('$');
        int k=qc.size(), idx, n=s.size(), last=0, x;
        map<int,int> mp;
        map<int,char> seg;
        seg[0] = s[0];
        char c = s[0];
        for (int i=1; i<n; ++i) {
            if (s[i] == c) continue;
            mp[i - last]++;
            last = i;
            c = s[i];
            seg[i] = c;
        }
        vector<int> ans(k);
        for (int i=0; i<k; ++i) {
            c = qc[i], idx = qidx[i] + 1;
            if (s[idx] == c) {
                ans[i] = next(mp.end(), -1)->first;
                continue;
            }
            auto jt = seg.upper_bound(idx);
            auto it = next(jt, -1);
            if (it->first == idx) {  // 前接
                auto pt = next(it, -1);
                if (jt->first == idx+1) {  // 后接
                    mp[1]--;
                    char prev_c = pt->second;
                    if (prev_c == c && c == jt->second) {
                        x = it->first - pt->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        auto nt = next(jt);
                        x = nt->first - jt->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[nt->first - pt->first]++;
                        seg.erase(idx);
                        seg.erase(jt->first);
                    } else if (prev_c == c) {
                        x = it->first - pt->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x+1]++;
                        seg.erase(idx);
                    } else if (c == jt->second) {
                        auto nt = next(jt);
                        x = nt->first - jt->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x+1]++;
                        seg.erase(jt->first);
                        seg[idx] = c;
                    } else {
                        it->second = c;
                        mp[1]++;
                    }
                } else { // 后不接
                    if (pt->second == c) {
                        x = jt->first - idx;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x-1]++;
                        x = idx - pt->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x+1]++;
                        seg[idx+1] = s[idx+1];
                        seg.erase(idx);
                    } else {
                        x = jt->first - idx;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x-1]++;
                        it->second = c;
                        seg[idx+1] = s[idx+1];
                        mp[1]++;
                    }
                }
            } else {  // 前不接
                if (jt->first == idx+1) {  // 后接
                    auto nt = next(jt);
                    if (c == jt->second) {
                        x = jt->first - it->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x-1]++;
                        x = nt->first - jt->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x+1]++;
                        seg.erase(jt->first);
                        seg[idx] = c;
                    } else {
                        x = jt->first - it->first;
                        mp[x]--;
                        if (mp[x] == 0) mp.erase(x);
                        mp[x-1]++;
                        mp[1]++;
                        seg[idx] = c;
                    }
                } else { // 后不接
                    x = jt->first - it->first;
                    mp[x]--;
                    if (mp[x] == 0) mp.erase(x);
                    mp[idx - it->first]++;
                    mp[1]++;
                    mp[jt->first - idx - 1]++;
                    seg[idx] = c;
                    seg[idx+1] = s[idx+1];
                }
            }
            s[idx] = c;
            ans[i] = next(mp.end(), -1)->first;
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s, qc; VI qidx;
    s = "babacc", qc = "bcb", qidx = {1,3,3};
    for (auto vi : sol.longestRepeating(s,qc,qidx)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    s = "abyzz", qc = "aa", qidx = {2,1};
    for (auto vi : sol.longestRepeating(s,qc,qidx)) { std::cout << vi << ' '; }
    std::cout << std::endl;
    return 0;
}
