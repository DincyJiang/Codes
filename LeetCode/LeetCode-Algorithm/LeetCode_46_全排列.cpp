// 给定一个没有重复数字的序列，返回其所有可能的全排列。

// 示例:

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <vector>

using namespace std;

// 回溯法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{};
        func(nums, 0, nums.size() - 1, res);
        return res;
    }
    void func(vector<int>& nums, int index, int n, vector<vector<int>>& res) {
        if (index == n) {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < n; ++i) {
            swap(nums[i], nums[index]);
            func(nums, index + 1, n, res);
            swap(nums[i], nums[index]);
        }
    }
};