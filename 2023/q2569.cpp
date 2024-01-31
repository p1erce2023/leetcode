// 线段树模版来啦
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::priority_queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::vector;

class Solution {
public:
    void build_tree(int low, int high, int pos, vector<int>& arr, vector<int>& seg) {
        if (low == high) {
            seg[pos] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build_tree(low, mid, 2*pos+1, arr, seg);
        build_tree(mid+1, high, 2*pos+2, arr, seg);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];  // min, max, sum, or other suitable operation
    }

    int range_query_lazy(int low, int high, int pos, int qlow, int qhigh, vector<int>& seg, vector<int>& lazy) {
        if (lazy[pos] != 0) {
            seg[pos] += lazy[pos];
            if (low != high) {  // not a leaf node
                lazy[2*pos+1] += lazy[pos];
                lazy[2*pos+2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if (qlow <= low && high <= qhigh) return seg[pos];
        if (high < qlow || low > qhigh) return 0;
        int mid = (low + high) / 2;
        return range_query_lazy(low, mid, 2*pos+1, qlow, qhigh, seg, lazy) +
            range_query_lazy(mid+1, high, 2*pos+2, qlow, qhigh, seg, lazy);
    }

    void update_range_lazy(int low, int high, int pos, int qlow, int qhigh, vector<int>& seg, vector<int>& lazy) {
        if (low > high) return;

        if (lazy[pos] != 0) {
            seg[pos] = high - low + 1 - seg[pos];
            if (low != high) {  // not a leaf node
                lazy[2*pos+1] = 1 - lazy[2*pos+1];
                lazy[2*pos+2] = 1 - lazy[2*pos+2];
            }
            lazy[pos] = 0;
        }

        if (qlow <= low&& high <= qhigh) {  // total overlap
            seg[pos] = high - low + 1 - seg[pos];
            if (low != high) {
                lazy[2*pos+1] = 1 - lazy[2*pos+1];
                lazy[2*pos+2] = 1 - lazy[2*pos+2];
            }
            return;
        }

        if (low > qhigh || high < qlow) return;  // no overlap

        int mid = (low + high) / 2;
        update_range_lazy(low, mid, 2*pos+1, qlow, qhigh, seg, lazy);
        update_range_lazy(mid+1, high, 2*pos+2, qlow, qhigh, seg, lazy);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long s = std::accumulate(nums2.begin(), nums2.end(), 0ll);
        vector<long long> ans;
        int n = nums1.size();
        vector<int> seg(4*n), lazy(4*n);
        build_tree(0, n-1, 0, nums1, seg);
        for (auto& q : queries) {
            if (q[0] == 1) {
                update_range_lazy(0, n-1, 0, q[1], q[2], seg, lazy);
            } else if (q[0] == 2) {
                s += 1ll * range_query_lazy(0, n-1, 0, 0, n-1, seg, lazy) * q[1];
            } else {
                ans.push_back(s);
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums1, nums2; vector<vector<int>> queries;
    nums1 = {1,0,1}, nums2 = {0,0,0}, queries = {{1,1,1},{2,1,0},{3,0,0}};
    for (int xx : s.handleQuery(nums1, nums2, queries))
        std::cout << xx << ' ';
    std::cout << std::endl;
    nums1 = {1}, nums2 = {5}, queries = {{2,0,0},{3,0,0}};
    for (int xx : s.handleQuery(nums1, nums2, queries))
        std::cout << xx << ' ';
    std::cout << std::endl;
    return 0;
}
