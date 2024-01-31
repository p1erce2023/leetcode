#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size(), x, t, k;
        string s(""), ans(n, ' ');
        vector<int> i2g(n, -1);
        vector<unordered_set<int>> g;
        vector<vector<int>> dg(n, vector<int>());
        char c = 'a';
        for (int i=0; i < n; i++) {
            if (lcp[i][i] != n - i) return s;
            if (ans[i] == ' ') {
                if (c > 'z') return s;
                ans[i] = c;
                c++;
            }
            for (int j=i+1; j < n; j++) {
                x = lcp[i][j];
                if (x != lcp[j][i]) return s;
                if (x + j > n) return s;
                if (x && j + 1 < n && x != lcp[i+1][j+1] + 1) return s;
                if (x) {
                    if (ans[j] == ' ')
                        ans[j] = ans[i];
                    else if (ans[j] != ans[i])
                        return s;
                }
            }
        }
        for (int i=0; i < n - 1; i++) {
            for (int j=i+1; j<n; j++) {
                if (lcp[i][j] == 0 && ans[i] == ans[j]) return s;
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<vector<int>> lcp;
    lcp = {{3, 2, 0}, {2, 2, 1}, {0, 1, 1}};
    std::cout << s.findTheString(lcp) << std::endl;
    lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    std::cout << s.findTheString(lcp) << std::endl;
    lcp = {{3, 0, 1}, {0, 2, 1}, {1, 1, 1}};
    std::cout << s.findTheString(lcp) << std::endl;
    lcp = {{2,2},{2,1}};
    std::cout << s.findTheString(lcp) << std::endl;
    lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    std::cout << s.findTheString(lcp) << std::endl;
    lcp = {{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}};
    std::cout << s.findTheString(lcp) << std::endl;
    lcp = {{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,3}};
    std::cout << s.findTheString(lcp) << std::endl;
    return 0;
}