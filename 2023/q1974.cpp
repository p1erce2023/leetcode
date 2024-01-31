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
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

class Solution {
public:
    bool check_next(vector<int>& p) {
        int m=p.size(), i=m-1, j=0;
        vector<bool> used(m,false);
        while (i>0 && p[i]<p[i-1]) i--;
        if (i==0) return false;
        for (int k=0; k<i-1; k++) used[p[k]]=true;
        i--;
        p[i]++;
        while (used[p[i]]) p[i]++;
        used[p[i]] = true;
        i++;
        while (i<m) {
            while (used[j]) j++;
            p[i++] = j++;
        }
        return true;
    }

    int get_score(vector<int>& p, vector<vector<int>>& score) {
        int s=0;
        for (int i=0; i<p.size(); i++) s+=score[i][p[i]];
        return s;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=students.size(), n=students[0].size();
        vector<vector<int>> score(m, vector<int>(m,0));
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
                for (int k=0; k<n; k++)
                    if (students[i][k] == mentors[j][k])
                        score[i][j]++;
        vector<int> p(m);
        std::iota(p.begin(), p.end(), 0);
        int ans=get_score(p, score);
        while (check_next(p))
            ans = max(ans, get_score(p, score));
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // parameters init
    vector<vector<int>> students, mentors;
    students = {{1,1,0},{1,0,1},{0,0,1}}, mentors = {{1,0,0},{0,0,1},{1,1,0}};
    OUT(sol.maxCompatibilitySum(students, mentors));
    students = {{0,0},{0,0},{0,0}}, mentors = {{1,1},{1,1},{1,1}};
    OUT(sol.maxCompatibilitySum(students, mentors));
    return 0;
}
