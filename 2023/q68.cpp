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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n=words.size(), lw=words[0].size(), w, ws=0;
        for (int i=1; i<n; ++i) {
            w = words[i].size();
            if (lw+1+w <= maxWidth) {
                lw += 1+w;
            } else {
                int sc = i-1-ws;
                string line;
                if (sc==0) {
                    line.append(words[ws]);
                    line.append(string(maxWidth-words[ws].size(), ' '));
                } else {
                    int q=(maxWidth-lw)/sc, r=(maxWidth-lw)%sc;
                    line.append(words[ws]);
                    for (int j=ws+1; j<i; ++j) {
                        string sp(1+q, ' ');
                        if (r) {sp.push_back(' ');--r;}
                        line.append(std::move(sp));
                        line.append(words[j]);
                    }
                }
                ans.push_back(std::move(line));
                ws = i;
                lw = words[i].size();
            }
        }
        string line;
        line.append(words[ws]);
        for (int j=ws+1; j<n; ++j) {
            line.push_back(' ');
            line.append(words[j]);
        }
        line.append(string(maxWidth-line.size(), ' '));
        ans.push_back(std::move(line));
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<string> words; int maxWidth;
    words = {"This", "is", "an", "example", "of", "text", "justification."};
    maxWidth = 16;
    for (auto vi : sol.fullJustify(words, maxWidth)) { std::cout << vi << "|\n"; }
    std::cout << std::endl;
    return 0;
}
