/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/

#include <vector>
#include <queue>
using namespace std;

// BFS和图的最短路径
// 可以用图的最短路径方法对问题建模
class Solution {
public:
    int numSquares(int n) {
        // 第一个int表示具体是第几个数字，第二个int表示之后建立的图中经历的几段路径
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        // 使用一个访问数组，访问过的节点就不再重复访问
        vector<bool> visited(n+1, false);
        visited[n] = true;

        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1; ; ++i) {
                int a = num - i*i;
                if (a < 0) break;
                if (a == 0) return step + 1;
                if (!visited[a]) {
                    q.push(make_pair(a, step + 1));
                    visited[a] = true;
                }
            }
        }
    }
};