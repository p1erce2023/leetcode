#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <deque>
using std::priority_queue;
using std::vector;
using std::deque;

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        priority_queue<int> pq_max(nums.begin(), nums.end());
        deque<int> tq;
        int ans = 0;
        while (!pq_max.empty()) {
            int a = pq_max.top();
            pq_max.pop();
            if (!tq.empty() && tq[0] > a) {
                tq.pop_front();
                tq.push_back(a);
                ans++;
            } else {
                tq.push_back(a);
            }
        }
        return ans;
    }
};
/*
[1,3,5,2,1,3,1]
     x          5
   5,x          3
   5,x,    x    3 3
   5,x,3   x    3,2
 3,5,1,3   1    2,1
 3,5,1,3,2,1,1

5 5 5 1
1       5

*/

int main() {
    auto s = Solution();
    vector<int> nums = {1,3,5,2,1,3,1};
    std::cout << s.maximizeGreatness(nums) << std::endl;
    nums = {1,2,3,4};
    std::cout << s.maximizeGreatness(nums) << std::endl;
    nums = {5,5,5,1};
    std::cout << s.maximizeGreatness(nums) << std::endl;
    nums = {5,5,5};
    std::cout << s.maximizeGreatness(nums) << std::endl;
    nums = {1,3,5,2,1,3,1,5,5,5};
    std::cout << s.maximizeGreatness(nums) << std::endl;
    return 0;
}