/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// 通过
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        assert(m > 0);
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (searchWord(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    // 从board[startx][starty]开始，寻找word[index...word.size()]
    bool searchWord(const vector<vector<char>> &board, const string& word,
                    int index, int startx, int starty) {
        if (index == word.size() - 1) {
            // index达到最大值，看看board[startx][starty]是否是最后一个字符
            return board[startx][starty] == word[index];
        }
        if (board[startx][starty] == word[index]) {
            visited[startx][starty] = true;
            // 从startx, starty出发，向四个方向寻找
            for (int i = 0; i < 4; ++i) {
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                // 判断新的坐标没有越界，并且没有被访问过
                if (inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord(board, word, index + 1, newx, newy)) {
                        return true;
                }
            }
            visited[startx][starty] = false;
        }
        return false;
    }
    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

private:
    int d[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n; // m是行数，n是列数
    vector<vector<bool>> visited; //访问数组
};

// 网上答案。通过
namespace sss {
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        bool res = search(board, word, idx + 1, i - 1, j, visited) 
                 || search(board, word, idx + 1, i + 1, j, visited)
                 || search(board, word, idx + 1, i, j - 1, visited)
                 || search(board, word, idx + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};
}