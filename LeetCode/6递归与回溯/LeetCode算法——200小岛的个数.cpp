/*
给定 '1'（陆地）和 '0'（水）的二维网格图，计算岛屿的数量。一个岛被水包围，并且通过水平或垂直连接相邻的陆地而形成。你可以假设网格的四个边均被水包围。

示例 1:

11110
11010
11000
00000
答案: 1

示例 2:

11000
11000
00100
00011
答案: 3

*/

#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include <cassert>
using namespace std;

// 递归深搜，
void DFS(const vector<vector<char>> &vec, vector<vector<bool>> &visited, int x, int y) {
    // 不要越界
    if (x < 0 || x >= vec.size()) return;
    if (y < 0 || y >= vec[0].size()) return;
    // 递归终止条件
    if (vec[x][y] != '1' || visited[x][y]) return;
    visited[x][y] = true; // 当前节点访问过
    // 顺序可以变
    DFS(vec, visited, x - 1, y); // 上
    DFS(vec, visited, x + 1, y); // 下
    DFS(vec, visited, x, y - 1); // 左
    DFS(vec, visited, x, y + 1); // 右
}

int nums(const vector<vector<char>> &vec) {
    if (vec.empty() || vec[0].empty()) return 0;
    int m = vec.size(), n = vec[0].size(), res = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (vec[i][j] == '1' && !visited[i][j]) { // 当时是岛屿，并且没有被访问过
                DFS(vec, visited, i, j);
                ++res;
            }
    return res;
}

int main () {
    int M;
    cin >> M;
    vector<vector<char>> vec(M, vector<char>(M, 0));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            cin >> vec[i][j];

    cout << nums(vec);
    return 0;
}

namespace sss {
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if ( m == 0) 
            return 0;
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    // 从grid[x][y]的位置开始，进行floodfill
    // 保证(x,y)合法，且grid[x][y]是没有被访问过的陆地
    void dfs(vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1') {
                dfs(grid, newx, newy);
            }
        }
    }
private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    vector<vector<bool>> visited;
};
}


class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int island_num = 0;
        std::vector<std::vector<int> > mark;
        for (int i = 0; i < grid.size(); ++i){
            mark.push_back(std::vector<int>());
            for (int j = 0; j < grid[i].size(); ++j){
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                if (grid[i][j] == '1' && mark[i][j] == 0){
                    BFS(mark, grid, i, j);
                    ++island_num;
                }
            }
        }
        return island_num;
    }

private:
    void DFS(std::vector<std::vector<int> > &mark,
             std::vector<std::vector<char> > &grid,
             int x, int y){
        mark[x][y]=1; //标记已搜索的地址
        static const int dx[] = {-1, 1, 0, 0};  //方向数组
        static const int dy[] = {0, 0, -1, 1};
        for (int i=0; i<4; ++i){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= mark.size() || //超出数组边界时
                newy < 0 || newy >= mark[newx].size()){
                continue;
            }
            if (mark[newx][newy] != 1 && grid[newx][newy] != '0'){
                DFS(mark, grid, newx, newy);
            }
        }
    }
    void BFS (std::vector<std::vector<int> > &mark,
              std::vector<std::vector<char> > &grid,
              int x, int y){
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        std::queue<std::pair<int, int> > Q;
        Q.push(std::make_pair(x,y));
        mark[x][y] = 1;
        while (!Q.empty()){
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; ++i){
                int newx = dx[i] + x;
                int newy = dy[i] + y;
                if (newx < 0 || newx >= mark.size() ||
                    newy < 0 || newy >= mark[newx].size()){
                    continue;
                }
                if (mark[newx][newy] == 0 && grid[newx][newy] == '1'){
                    Q.push(std::make_pair(newx, newy));
                    mark[newx][newy] = 1;
                }
            }
        }
    }

};

int main(){
    std::vector<std::vector<char> > grid;
    char str[10][10] = {"11100", "11000", "00100", "00011"};
    for (int i = 0; i < 4; ++i){
        grid.push_back(std::vector<char>());
        for(int j = 0; j < 5; ++j){
            grid[i].push_back(str[i][j]);
        }
    }
    Solution solve;
    printf("%d\n", solve.numIslands(grid));
    return 0;
}