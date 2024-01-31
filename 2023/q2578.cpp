#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

class Solution {
public:
    int splitNum(int num) {
        string s = std::to_string(num);
        vector<int> digits;
        for (auto c : s) {
            digits.push_back(c - '0');
        }
        if (digits.size() % 2 == 1)
            digits.push_back(0);
        std::sort(digits.begin(), digits.end());
        string a, b;
        for (int i = 0; i < digits.size(); i += 2) {
            a.append(std::to_string(digits[i]));
            b.append(std::to_string(digits[i + 1]));
        }
        return std::stoi(a) + std::stoi(b);
    }
};

int main() {
    auto s = Solution();
    std::cout << s.splitNum(4325) << std::endl;
    return 0;
}