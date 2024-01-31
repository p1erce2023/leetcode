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
using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
class Solution {
public:
    pair<bool, VI> f(int i, int n, int st, int fst, VI& P, VVI& mem1, vector<VVI>& mem2) {
        if (st == fst) return {true, {}};
        if (i==n) return {false, {}};
        if (mem1[i][st] != -1) return {mem1[i][st], mem2[i][st]};
        auto [psb1, pp1] = f(i+1,n,st|P[i],fst,P,mem1,mem2);
        if (psb1) pp1.push_back(i);
        auto [psb2, pp2] = f(i+1,n,st,fst,P,mem1,mem2);
        bool psb=true; VI pp;
        if (psb1 && psb2) {
            if (pp1.size() <= pp2.size())
                pp = std::move(pp1);
            else
                pp = std::move(pp2);
        } else if (psb1) {
            pp = std::move(pp1);
        } else if (psb2) {
            pp = std::move(pp2);
        } else {
            psb=false;
        }
        mem1[i][st] = psb;
        mem2[i][st] = pp;
        return {psb, pp};
    }
    VI smallestSufficientTeam(vector<string>& R, vector<vector<string>>& P1) {
        unordered_map<string, int> mp;
        int m=R.size(), st=0, n=P1.size();
        for (int i=0; i<m; ++i) {
            st |= 1<<i;
            mp[R[i]] = i;
        }
        VI P(n,0);
        for (int i=0; i<n; ++i) {
            for (auto& s : P1[i])
                P[i] |= 1<<mp[s];
        }
        VVI mem1(n, VI(st+1,-1));
        vector<VVI> mem2(n, VVI(st+1, VI()));
        return f(0,n,0,st,P,mem1,mem2).second;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
