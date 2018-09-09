/*
LeetCode 200 岛屿的个数
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(const vector<vector<char>> &vec, vector<vector<bool>> &visited, int x, int y) {
    if (x < 0 || x >= vec.size()) return;
    if (y < 0 || y >= vec[0].size()) return;
    if (vec[x][y] != '1' || visited[x][y]) return;
    visited[x][y] = true;
    DFS(vec, visited, x - 1, y);
    DFS(vec, visited, x + 1, y);
    DFS(vec, visited, x, y - 1);
    DFS(vec, visited, x, y + 1);
}

int nums(const vector<vector<char>> &vec) {
    if (vec.empty() || vec[0].empty()) return 0;
    int m = vec.size(), n = vec[0].size(), res = 0;
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] == '1' && !visited[i][j]) {
                DFS(vec, visited, i, j);
                ++res;
            }
        }
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