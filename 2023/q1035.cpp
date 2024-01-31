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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    int f(int i, int n, vector<int>& A, vector<vector<int>>& Ad, int j, int m, vector<int>& B, vector<vector<int>>& Bd, vector<vector<int>>& mem) {
        if (i>=n || j>=m) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int ans=f(i+1,n,A,Ad,j,m,B,Bd,mem);
        for (int x : Bd[A[i]]) {
            if (x<j) continue;
            ans = max(ans, 1+f(i+1,n,A,Ad,x+1,m,B,Bd,mem));
        }
        return mem[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n=A.size(), m=B.size();
        vector<vector<int>> Ad(2001), Bd(2001), mem(n+1, vector<int>(m+1,-1));
        for (int i=0; i<n; i++) Ad[A[i]].push_back(i);
        for (int i=0; i<m; i++) Bd[B[i]].push_back(i);
        return f(0,n,A,Ad,0,m,B,Bd,mem);
    }
    // 原来就是个LCS，明眼人一眼看出，我却懵懵懂懂，只觉得有些熟悉，似曾相识
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol.);
    return 0;
}
