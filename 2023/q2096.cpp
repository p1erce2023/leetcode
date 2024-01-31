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

/**
 * Definition for a binary tree node.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
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
    unordered_map<int,string> path;
    int s, t;

    void dfs(TreeNode* x, string& p) {
        if (x->val == s) {
            path[0] = p;
            if (path.size() == 2) return;
        } else if (x->val == t) {
            path[1] = p;
            if (path.size() == 2) return;
        } 
        if (x->left) {
            p.push_back('L');
            dfs(x->left, p);
            p.pop_back();
        }
        if (path.size() == 2) return;
        if (x->right) {
            p.push_back('R');
            dfs(x->right, p);
            p.pop_back();
        }
    }

    string getDirections(TreeNode* root, int ss, int tt) {
        string p;
        s = ss, t = tt;
        dfs(root, p);
        string ans, a=path[0], b=path[1];
        int i=0;
        while (i < min(a.size(), b.size())) {
            if (a[i] != b[i]) break;
            ++i;
        }
        ans.append(string(a.size()-i, 'U'));
        ans.append(b.substr(i));
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(6);
    OUT(sol.getDirections(root, 3, 6));
    return 0;
}
