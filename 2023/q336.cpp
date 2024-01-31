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
    bool palin(string& w, int i, int j) {
        while (i < j)
            if (w[i++] != w[j--])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> d;
        unordered_map<string, vector<int>> pref;
        int n = words.size(), m;
        for (int i=0; i<n; i++) {
            d[words[i]] = i;
            m = words[i].size();
            for (int j=0; j<m; j++)
                if (palin(words[i], j, m-1))
                    pref[words[i].substr(0,j)].push_back(i);
            pref[words[i]].push_back(i);
        }
        string x;
        for (int i=0; i<n; i++) {
            x.clear();
            m = words[i].size();
            for (int j=m-1; j>=0; j--) {
                if (palin(words[i], 0, j) && d.count(x) && d[x] != i)
                    ans.push_back({d[x], i});
                x.push_back(words[i][j]);
            }
            for (int k : pref[x])
                if (k != i)
                    ans.push_back({k, i});
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    vector<string> words;
    // parameters init
    words = {"abcd","dcba","lls","s","sssll"};
    for (auto& v :sol.palindromePairs(words)) {
        std::cout << '[';
        for (int x : v) std::cout << x << ", ";
        std::cout << "], ";
    }
    std::cout << '\n';
    words = {"bat","tab","cat"};
    for (auto& v :sol.palindromePairs(words)) {
        std::cout << '[';
        for (int x : v) std::cout << x << ", ";
        std::cout << "], ";
    }
    std::cout << '\n';
    words = {"a",""};
    for (auto& v :sol.palindromePairs(words)) {
        std::cout << '[';
        for (int x : v) std::cout << x << ", ";
        std::cout << "], ";
    }
    std::cout << '\n';
    words = {"ab","b", "a"};
    for (auto& v :sol.palindromePairs(words)) {
        std::cout << '[';
        for (int x : v) std::cout << x << ", ";
        std::cout << "], ";
    }
    std::cout << '\n';
    words = {"ddab", "ab","ba", "bacc"};
    for (auto& v :sol.palindromePairs(words)) {
        std::cout << '[';
        for (int x : v) std::cout << x << ", ";
        std::cout << "], ";
    }
    std::cout << '\n';
    return 0;
}
