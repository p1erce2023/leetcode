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

/**
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
    int dfs(int d, TreeNode* x, vector<int>& h, vector<int>& label, vector<pair<int,int>>& layer) {
        int hl=0, hr=0, hh;
        label[x->val] = d;
        if (x->left) hl = 1 + dfs(d+1, x->left, h, label, layer);
        if (x->right) hr = 1 + dfs(d+1, x->right, h, label, layer);
        hh = max(hl, hr);
        if (hh > layer[d].first)
            layer[d].second = layer[d].first, layer[d].first = hh;
        else if (hh > layer[d].second)
            layer[d].second = hh;
        return h[x->val] = max(hl, hr);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n=1e5+1;
        vector<pair<int, int>> layer(n, {-1,-1});
        vector<int> h(n+1,-1), label(n+1,-1);
        dfs(0, root, h, label, layer);
        vector<int> ans;
        for (int q : queries) {
            auto& ly = layer[label[q]];
            ans.push_back(label[q] + ((h[q] == ly.first)? ly.second : ly.first));
            // 三元运算符，优先级很低！
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    OUT(sol.);
    return 0;
}
