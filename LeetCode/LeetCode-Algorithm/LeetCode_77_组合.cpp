// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

// 示例:

// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <vector>

using namespace std;

// 回溯法
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res{};
        if (n <= 0 || n < k) return res;
        vector<int> vec{};
        func(n, 1, k, vec, res);
        return res;
    }
    void func(int n, int index, int k, vector<int>& vec, vector<vector<int>>& res) {
        if (vec.size() == k) {
            res.push_back(vec);
            return;
        }
        for (int i = index; i <= n; ++i) {
            vec.push_back(i);
            func(n, i + 1, k, vec, res);
            vec.pop_back();
        }
    }
};

// 剪枝优化
class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res{};
        if (n <= 0 || n < k) return res;
        vector<int> vec{};
        func(n, 1, k, vec, res);
        return res;
    }
    void func(int n, int index, int k, vector<int>& vec, vector<vector<int>>& res) {
        if (vec.size() == k) {
            res.push_back(vec);
            return;
        }
        for (int i = index; i <= n - (k - vec.size()) + 1; ++i) {
            vec.push_back(i);
            func(n, i + 1, k, vec, res);
            vec.pop_back();
        }
    }
};