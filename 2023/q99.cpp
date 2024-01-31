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
    void recoverTree(TreeNode* root) {
        TreeNode *p=root, *q, *la=nullptr, *a=nullptr, *b;
        while (p) {
            if (p->left) {
                q = p->left;
                while (q->right && q->right != p)
                    q = q->right;
                if (q->right) {
                    if (la != nullptr && la->val > p->val) {
                        if (a == nullptr) a = la;
                        b = p;
                    }
                    la = p;
                    q->right = nullptr;
                    p = p->right;
                } else {
                    q->right = p;
                    p = p->left;
                }
            } else {
                if (la != nullptr && la->val > p->val) {
                    if (a == nullptr) a = la;
                    b = p;
                }
                la = p;
                p = p->right;
            }
        }
        int c = a->val;
        a->val = b->val;
        b->val = c;
    }
};

class Solution2 {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> stk={root};
        TreeNode *p = root, *t, *la=nullptr, *a=nullptr, *b=nullptr;
        while (p->left) {
            p = p->left;
            stk.push_back(p);
        }
        while (!stk.empty()) {
            t = stk.back();
            if (la != nullptr && la->val > t->val) {
                if (a==nullptr)
                    a=la, b=t;
                else {
                    b=t;
                    break;
                }
            }
            la = t;
            stk.pop_back();
            if (t->right) {
                t = t->right;
                stk.push_back(t);
                while (t->left) {
                    t = t->left;
                    stk.push_back(t);
                }
            }
        }
        int c = a->val;
        a->val = b->val;
        b->val = c;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(3);
    // root->left->right = new TreeNode(2);
    // sol.recoverTree(root);
    // OUT(root->val);
    // OUT(root->left->val);
    // OUT(root->left->right->val);
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(2);
    sol.recoverTree(root2);
    OUT(root2->val);
    OUT(root2->right->left->val);
    return 0;
}

// Morris Traversal 挺酷的，就是有点繁琐
// 为了保证不改变原结构，在 L61 的判断里，尤其是 L67，又把增上去的 thread 边给删除了
