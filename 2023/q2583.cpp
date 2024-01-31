/* *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // bfd + min_heaq
        priority_queue<long long, vector<long long>, std::greater<long long>> h;
        vector<TreeNode*> q = {root}, nq;
        long long s;
        while (!q.empty()) {
            nq.clear();
            s = 0;
            for (auto t : q) {
                if (t->left) nq.push_back(t->left);
                if (t->right) nq.push_back(t->right);
                s += t->val;
            }
            // std::cout << s << std::endl;
            if (h.size() <= k || s > h.top()) {
                h.push(s);
            }
            if (h.size() > k) h.pop();
            std::swap(nq, q);
        }
        if (h.size() < k) return -1;
        else return h.top();
    }
};

int main() {
    auto s = Solution();
    vector<TreeNode> v(10, TreeNode());
    for (int i = 0; i < 10; i++) v[i].val = i;
    TreeNode* root = &v[5];
    v[5].left = &v[8];
    v[5].right = &v[9];
    v[8].left = &v[2];
    v[8].right = &v[1];
    v[9].left = &v[3];
    v[9].right = &v[7];
    v[2].left = &v[4];
    v[2].right = &v[6];
    std::cout << s.kthLargestLevelSum(root, 2) << std::endl;
    return 0;
}