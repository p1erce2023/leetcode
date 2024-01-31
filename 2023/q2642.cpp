#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
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

/*
const int INF = 0x3f3f3f3f;

class Graph {
    int sz;
    vector<vector<int> > dis;
public:
    Graph(int n, vector<vector<int>>& edges) {
        sz = n;
        dis.assign(n, vector<int>(n, INF));
        for(auto &it: edges) {
            int &v = dis[it[0]][it[1]];
            v = min(v, it[2]);
        }
        for(int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }

    void addEdge(vector<int> edge) {
        auto &it = edge;
        for(int i = 0; i < sz; ++i)
            for(int j = 0; j < sz; ++j)
                dis[i][j] = min(dis[i][j], dis[i][it[0]] + it[2] + dis[it[1]][j]);
    }

    int shortestPath(int node1, int node2) {
        int &v = dis[node1][node2];
        return v < INF ? v : -1;
    }
};
*/

/* all pairs shortest path, with edge revision */
/* 其实看参数限制，就算裸实现每次查找，也应该是能通过，的确看到很多人的代码是裸搜
   倒也没问题，毕竟 addedge 的update 也是 O(n^2)，除非还要加一些 lazy 的 update 以节省常数因子
   好像也并不能节省
   写起来甚至比 dijkstra 还简洁
*/
class Graph {
public:
    vector<vector<int>> d;

    Graph(int n, vector<vector<int>>& edges) {
        d = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &e : edges)
            d[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    void addEdge(vector<int> edge) {
        int n=d.size();
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                d[i][j] = min(d[i][j], d[i][edge[0]]+edge[2]+d[edge[1]][j]);
    }

    int shortestPath(int node1, int node2) {
        return d[node1][node2] == 1e9? -1 : d[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main() {
    Graph* obj = new Graph(4, {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}});
    std::cout << obj->shortestPath(3, 2) << std::endl;
    std::cout << obj->shortestPath(0, 3) << std::endl;
    obj->addEdge({1,3,4});
    std::cout << obj->shortestPath(0, 3) << std::endl;
    return 0;
}


