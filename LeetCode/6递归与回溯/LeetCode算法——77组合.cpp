/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n <= 0 || k <= 0 || n < k) return res;
        vector<int> c;
        help(n, k, res, c, 1);
        return res;
    }
private:
    void help(int n, int k, vector<vector<int>>& res, vector<int>& c, int start) {
        if (c.size() == k) {
            res.push_back(c);
            return;
        }
        for (int i = start; i <= n - (k - c.size()) + 1; ++i) {
            c.push_back(i);
            help(n, k, res, c, i+1);
            c.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        if (n <= 0 || k <= 0 || k > n) return res;
        vector<int> c;
        generateCombinations(n, k, 1, c);
        return res;
    }
private:
    // 求解C(n,k), 当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int>& c) {
        if (c.size() == k) {
            res.push_back(c);
            return;
        }
        for (int i = start; i <= n; ++i) {
            c.push_back(i);
            generateCombinations(n, k, i + 1, c);
            // 状态回溯
            c.pop_back();
        }
    }

private:
    vector<vector<int> > res;
};

// 进行剪枝优化
class Solution2 {
public:
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        if (n <= 0 || k <= 0 || k > n) return res;
        vector<int> c;
        generateCombinations(n, k, 1, c);
        return res;
    }
private:
    // 求解C(n,k), 当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int>& c) {
        if (c.size() == k) {
            res.push_back(c);
            return;
        }
        // 还有k - c.size()个空位，所以[i...n]中至少要有k-c.size()个元素
        // i最多为 n - (k-csize()) + 1
        for (int i = start; i <= n - (k-c.size()) + 1; ++i) {
            c.push_back(i);
            generateCombinations(n, k, i + 1, c);
            // 状态回溯
            c.pop_back();
        }
    }

private:
    vector<vector<int> > res;
};

