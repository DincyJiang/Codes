// 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 示例:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// 给定 word = "ABCCED", 返回 true.
// 给定 word = "SEE", 返回 true.
// 给定 word = "ABCB", 返回 false.

#include <vector>
#include <string>

using namespace std;

// 回溯，使用visited数组记录访问状态
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, m, n, visited)) return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int index, int i, int j, int m, int n, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || board[i][j] != word[index])
            return false;
        visited[i][j] = true;
        bool res = search(board, word, index+1, i-1, j, m, n, visited) ||
                   search(board, word, index+1, i+1, j, m, n, visited) ||
                   search(board, word, index+1, i, j-1, m, n, visited) ||
                   search(board, word, index+1, i, j+1, m, n, visited);
        visited[i][j] = false;
        return res;
    }
};

// 还可以不用visited数组，直接对board数组进行修改，将其遍历过的位置改为#号，记得递归调用完后需要恢复之前的状态，参见代码如下：
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, m, n)) return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, const string& word, int index, int i, int j, const int& m, const int& n) {
        if (index == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) return false;
        char c = board[i][j];
        board[i][j] = '#';
        bool res = search(board, word, index+1, i-1, j, m, n) ||
                   search(board, word, index+1, i+1, j, m, n) ||
                   search(board, word, index+1, i, j-1, m, n) ||
                   search(board, word, index+1, i, j+1, m, n);
        board[i][j] = c;
        return res;
    }
};