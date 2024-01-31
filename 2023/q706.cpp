#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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

class MyHashMap {
public:
    vector<pair<int,int>> v;
    int n;
    hash<int> hasher;
    
    MyHashMap() {
        n = 10000;
        v.resize(n, {-1, -1});
        hasher = hash<int>();
    }
    
    void put(int key, int value) {
        int idx = hasher(key) % n;
        while (v[idx].first != -1 && v[idx].first != key) {
            ++idx;
            if (idx == n) idx = 0;
        }
        v[idx] = {key, value};
    }
    
    int get(int key) {
        int idx = hasher(key) % n;
        while (v[idx].first != -1 && v[idx].first != key) {
            ++idx;
            if (idx == n) idx = 0;
        }
        return v[idx].second;
    }
    
    void remove(int key) {
        int idx = hasher(key) % n, j, k;
        while (v[idx].first != -1 && v[idx].first != key) {
            ++idx;
            if (idx == n) idx = 0;
        }
        if (v[idx].first == -1) return;
        v[idx] = {-1, -1};
        j = idx;
        while (1) {
            j = (j+1) % n;
            if (v[j].first == -1) return;
            k = hasher(v[j].first) % n;
            if (idx <= j) {
                if (idx < k && k <= j)
                    continue;
            } else {
                if (idx < k || k <= j)
                    continue;
            }
            swap(v[idx], v[j]);
            idx = j;
        }
    }
};

int main() {
    
    auto sol = Solution();
    // parameters init
    OUT(sol);
    return 0;
}
