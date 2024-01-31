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
    vector<string> f(int idx, int n, string& s, Trie& trie, vector<vector<string>>& mem1, vector<int>& mem2) {
        if (idx == n) return {""};
        if (mem2[idx] != -1) return mem1[idx];
        mem2[idx] = 1;
        Trie* p = &trie;
        vector<string> ans;
        for (int i=idx; i<n; ++i) {
            if (p->ch[s[i]-'a'] == nullptr)
                break;
            p = p->ch[s[i]-'a'];
            if (p->e) {
                for (auto res : f(i+1,n,s,trie,mem1,mem2)) {
                    string line = s.substr(idx,i+1-idx);
                    if (!res.empty()) {
                        line.push_back(' ');
                        line.append(res);
                    }
                    ans.push_back(std::move(line));
                }
            }
        }
        return mem1[idx] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& wd : wordDict) trie.insert(wd);
        int n = s.size();
        vector<vector<string>> mem1(21);
        vector<int> mem2(21,-1);
        return f(0, n, s, trie, mem1, mem2);
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string s;
    vector<string> wordDict;
    s = "catsanddog", wordDict = {"cat","cats","and","sand","dog"};
    for (auto vi : sol.wordBreak(s, wordDict)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    return 0;
}
