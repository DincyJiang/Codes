// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：

// 答案中不可以包含重复的四元组。

// 示例：

// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include <vector>
#include <set>

using namespace std;

/*
LeetCode中关于数字之和还有其他几道，分别是Two Sum 两数之和，3Sum 三数之和，3Sum Closest 最近三数之和，
虽然难度在递增，但是整体的套路都是一样的，在这里为了避免重复项，我们使用了STL中的set，其特点是不能有重复，
如果新加入的数在set中原本就存在的话，插入操作就会失败，这样能很好的避免的重复项的存在。
此题的O(n^3)解法的思路跟3Sum 三数之和基本没啥区别，就是多加了一层for循环，其他的都一样，代码如下：
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        for (int i = 0; i < nums_size - 3; ++i) {
            for (int j = i + 1; j < nums_size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue; // 跳过重复值
                int left = j + 1;
                int right = nums_size - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> vec{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(vec);
                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};