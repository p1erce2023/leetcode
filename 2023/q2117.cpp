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
using namespace std;
#define OUT(...) cout << __VA_ARGS__ << '\n'

using UMPII = unordered_map<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using LL = long long;

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int c2=0, c5=0, c0=0, last5=0, first5;
        long double s=0;
        long long x=1, MODLL=1e10;
        for (int i=left, j; i<=right; ++i) {
            j = i;
            while (j%2==0) {
                ++c2;
                j /= 2;
            }
            while (j%5==0) {
                ++c5;
                j /= 5;
            }
            s += log10(j);
            x = (x * j) % MODLL;
        }
        c0 = min(c2, c5);
        if (c2 - c0) {
            int j = c2 - c0;
            while (j--) 
                x = (x * 2) % MODLL;
            s += log10(2) * (c2 - c0);
        }
        if (c5 - c0) {
            int j = c5 - c0;
            while (j--) 
                x = (x * 5) % MODLL;
            s += log10(5) * (c5 - c0);
        }
        if (s >= 10) {
            first5 = pow(10, s - int(s) + 4);
            string last5(5, '0');
            for (int i=0; i<5 && x; ++i) {
                last5[4-i] = x%10 + '0';
                x /= 10;
            }
            return to_string(first5) + "..." + last5 + "e" + to_string(c0);
        } else {
            return to_string(x) + "e" + to_string(c0);
        }
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    int left, right;
    // left = 1, right = 4;
    // OUT(sol.abbreviateProduct(left, right));
    // left = 2, right = 11;
    // OUT(sol.abbreviateProduct(left, right));
    // left = 371, right = 375;
    // OUT(sol.abbreviateProduct(left, right));
    // left = 44, right = 9556;  // "10205...06688e2378"
    // OUT(sol.abbreviateProduct(left, right));
    left = 9236, right = 9301;
    OUT(sol.abbreviateProduct(left, right));
    return 0;
}
