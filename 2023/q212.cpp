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
struct Trie {
    Trie* ch[26] = {};
    bool e = false;
    void insert(string &w) {
        auto n = this;
        for (auto c : w) {
            if (n->ch[c - 'a'] == nullptr)
                n->ch[c - 'a'] = new Trie();
            n = n->ch[c - 'a'];
        }
        n->e = true;
    }
    bool search(string &w) {
        auto n = this;
        for (auto c : w) {
            if (n->ch[c - 'a'] == nullptr)
                return false;
            n = n->ch[c - 'a'];
        }
        return n->e;
    }
};
class Solution {
public:
    vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    void f(string& s, int i, int j, vector<vector<char>>& B, Trie* p, unordered_set<string>& res) {
        char c = B[i][j];
        if (c=='#' || p->ch[c-'a'] == nullptr) return;
        s.push_back(c);
        p = p->ch[c-'a'];
        B[i][j] = '#';
        if (p->e) res.insert(s);
        int m=B.size(), n=B[0].size(), ci, cj;
        for (auto [di,dj] : dirs) {
            ci=i+di, cj=j+dj;
            if (ci>=0 && ci<m && cj>=0 && cj<n)
                f(s,ci,cj,B,p,res);
        }
        s.pop_back();
        B[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& B, vector<string>& W) {
        Trie trie;
        for (auto& w : W) trie.insert(w);
        int m=B.size(), n=B[0].size();
        string s;
        unordered_set<string> res;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                f(s,i,j,B,&trie,res);
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<char>> board; vector<string> words;
    board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}, words = {"oath","pea","eat","rain"};
    for (auto vi : sol.findWords(board, words)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    return 0;
}
