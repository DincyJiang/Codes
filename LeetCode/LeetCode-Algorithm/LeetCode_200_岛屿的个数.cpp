// 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
// 一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

// 示例 1:

// 输入:
// 11110
// 11010
// 11000
// 00000

// 输出: 1
// 示例 2:

// 输入:
// 11000
// 11000
// 00100
// 00011

// 输出: 3

#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res{0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) { // 没有访问过的岛屿
                    DFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= grid.size() || // 越界
            y < 0 || y >= grid[0].size() || // 越界
            grid[x][y] != '1' || // 不是岛屿
            visited[x][y]) // 访问过
            return;
        visited[x][y] = true;
        DFS(grid, visited, x+1, y);
        DFS(grid, visited, x-1, y);
        DFS(grid, visited, x, y+1);
        DFS(grid, visited, x, y-1);
    }
};