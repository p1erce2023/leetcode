#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    std::stringstream ss;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string s;
        vector<TreeNode*> q={root}, nq;
        while (!q.empty()) {
            for (TreeNode* p : q) {
                if (p==nullptr) {
                    s.append(std::to_string(1001));
                    s.push_back(' ');
                } else {
                    s.append(std::to_string(p->val));
                    s.push_back(' ');
                    nq.push_back(p->left);
                    nq.push_back(p->right);
                }
            }
            q = std::move(nq);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int x;
        ss.str(data);
        // std::istringstream ss;
        // ss.str(data);
        ss >> x;
        if (x == 1001) return root;
        else root = new TreeNode(x);
        vector<TreeNode*> q={root}, nq;
        while (!ss.eof() && !q.empty()) {
            for (int i=0; i<q.size(); ++i) {
                ss >> x;
                if (x != 1001) {
                    q[i]->left = new TreeNode(x);
                    nq.push_back(q[i]->left);
                }
                ss >> x;
                if (x != 1001) {
                    q[i]->right = new TreeNode(x);
                    nq.push_back(q[i]->right);
                }
            }
            q = std::move(nq);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    Codec ser, deser;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string res = ser.serialize(root);
    OUT(res);
    auto p = deser.deserialize(res);
    OUT(p->val);

    root = NULL;
    p = deser.deserialize(ser.serialize(root));
    if (p)
        OUT(p->val);
    else
        OUT("empty TreeNode");
}
