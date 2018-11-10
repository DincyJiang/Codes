// 给定一个可包含重复数字的序列，返回所有不重复的全排列。

// 示例:

// 输入: [1,1,2]
// 输出:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        DFS(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void DFS(vector<int>& nums, int index, set<vector<int>>& res) {
        if (index == nums.size()) {
            res.insert(nums);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[index]) continue; // 跳过重复，不然超时
            swap(nums[i], nums[index]);
            DFS(nums, index+1, res);
            swap(nums[i], nums[index]);
        }
    }
};