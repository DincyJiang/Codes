// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

// 示例 1:

// 输入: [1,2,0]
// 输出: 3
// 示例 2:

// 输入: [3,4,-1,1]
// 输出: 2
// 示例 3:

// 输入: [7,8,9,11,12]
// 输出: 1
// 说明:

// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

#include <vector>

using namespace std;

// nums[0] = 1
// nums[1] = 2
// nums[2] = 3
// ......
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i{0}; i < n; ++i) {
            // 把nums[i]放在该放的位置上：nums[nums[i] - 1]
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i{0}; i < n; ++i) { // 如果对应位置上的数不正确则返回正确的数
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};