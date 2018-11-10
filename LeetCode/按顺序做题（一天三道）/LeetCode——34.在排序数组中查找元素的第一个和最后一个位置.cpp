// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 如果数组中不存在目标值，返回 [-1, -1]。

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]

#include <vector>

using namespace std;

// 使用两次二分查找法，第一次找到左边界，第二次调用找到右边界即可
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int left = 0, right = nums.size() - 1;
        while (left < right) { // 查找第一个不小于目标值的数
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) { // 查找第一个大于目标值的数
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right= mid;
        }
        res[1] = left - 1;
        return res;
    }
};