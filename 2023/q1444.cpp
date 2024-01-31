#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::map;
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
    int n, m, MOD=1e9+7;

    int f(vector<string>& pizza, int i, int j, int k, map<tuple<int, int, int>, int>& mem, map<tuple<int, int>, int>& mem2) {
        if (mem.find({i,j,k}) != mem.end()) return mem[{i,j,k}];
        if (mem2.find({i,j}) != mem2.end()) return 0;
        if (k == 1) {
            for (int ii=i; ii<m; ii++) {
                for (int jj=j; jj<n; jj++) {
                    if (pizza[ii][jj] == 'A') {
                        return mem[{i,j,k}] = 1;
                    }
                }
            }
            for (int ii=i; ii<m; ii++)
                for (int jj=j; jj<n; jj++)
                    mem2[{i,j}] = 0;
            return mem[{i,j,k}] = 0;
        }
        int ans = 0, min_i = m, min_j = n;
        for (int ii=i; ii<m-1; ii++) {
            for (int jj=j; jj<n; jj++) {
                if (pizza[ii][jj] == 'A') {
                    min_i = ii;
                    break;
                }
            }
            if (min_i != m) break;
        }
        for (int ii=min_i+1; ii<m; ii++) {
            ans = (0ll + ans + f(pizza, ii, j, k-1, mem, mem2)) % MOD;
        }
        for (int jj=j; jj<n-1; jj++) {
            for (int ii=i; ii<m; ii++) {
                if (pizza[ii][jj] == 'A') {
                    min_j = jj;
                    break;
                }
            }
            if (min_j != n) break;
        }
        for (int jj=min_j+1; jj<n; jj++) {
            ans = (0ll + ans + f(pizza, i, jj, k-1, mem, mem2)) % MOD;
        }
        return mem[{i,j,k}] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        map<tuple<int, int, int>, int> mem;  // i,j,k
        map<tuple<int, int>, int> mem2;
        return f(pizza,0,0,k,mem, mem2);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> pizza; int k;
    pizza = {"A..","AAA","..."}, k = 3;
    std::cout << sol.ways(pizza, k) << std::endl;
    pizza = {"A..","AA.","..."}, k = 3;
    std::cout << sol.ways(pizza, k) << std::endl;
    pizza = {"A..","A..","..."}, k = 1;
    std::cout << sol.ways(pizza, k) << std::endl;
    return 0;
}
