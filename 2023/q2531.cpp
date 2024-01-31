#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
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
using std::swap;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> c1(26,0), c2(26,0), k1, k2;
        for (char c : word1) {
            c1[c-'a']++;
            if (c1[c-'a'] == 1) k1.push_back(c-'a');
        }
        for (char c : word2) {
            c2[c-'a']++;
            if (c2[c-'a'] == 1) k2.push_back(c-'a');
        }
        int n1=k1.size(), n2=k2.size(), nn1, nn2, m1, m2;
        for (int x1 : k1) {
            nn1 = n1-(c1[x1] == 1);
            nn2 = n2+(c2[x1] == 0);
            for (int x2 : k2) {
                if (x1 == x2) {
                    if (n1==n2) return true;
                    else continue;
                }
                m2 = nn2 - (c2[x2] == 1);
                m1 = nn1 + (c1[x2] == 0);
                if (m1 == m2) return true;
            }
        }
        return false;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    string w1,w2;
    w1 = "ac", w2 = "caca";
    std::cout << sol.isItPossible(w1,w2) << std::endl;
    w1 = "ab", w2 = "abcc";
    std::cout << sol.isItPossible(w1,w2) << std::endl;
    w1 = "ab", w2 = "aa";
    std::cout << sol.isItPossible(w1,w2) << std::endl;
    w1 = "ac", w2 = "b";
    std::cout << sol.isItPossible(w1,w2) << std::endl;
    w1 = "abcc", w2 = "aab";
    std::cout << sol.isItPossible(w1,w2) << std::endl;
    w1 = "abcde", w2 = "fghij";
    std::cout << sol.isItPossible(w1,w2) << std::endl;
    return 0;
}
