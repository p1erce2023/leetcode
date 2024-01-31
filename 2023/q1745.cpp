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
    int mem[2001][5];
    bool palin(string& s, int i, int j) {
        while (i<j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    int f(string& s, int k, int i, int n) {
        if (mem[i][k] != -1)
            return mem[i][k];
        else if (k==1) {
            return mem[i][k] = palin(s,i,n-1);
        } else {
            for (int j=i; j<n-k+1; j++)
                if (palin(s,i,j)) {
                    mem[j][k] = f(s,k-1,j+1,n); // 这里多一个赋值，直接从2s+减到14ms，为什么？！
                    if (mem[j][k]) return true;
                }
            return mem[i][k] = false;
        }
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        memset(mem, -1, sizeof(mem));
        return f(s, 3, 0, n);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    s = "abcbdd";
    OUT(sol.checkPartitioning(s));
    s = "bcbddxy";
    OUT(sol.checkPartitioning(s));
    s = "bcbddacxyxca";
    OUT(sol.checkPartitioning(s));
    s = "bcbddaaddaa";
    OUT(sol.checkPartitioning(s));
    s = "aababbababba";
    OUT(sol.checkPartitioning(s));
    return 0;
}
