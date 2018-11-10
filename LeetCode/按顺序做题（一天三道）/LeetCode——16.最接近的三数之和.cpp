// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

#include <vector>

using namespace std;

/*
在之前那道 3Sum 三数之和的基础上又增加了些许难度，那么这道题让我们返回这个最接近于给定值的值，
即我们要保证当前三数和跟给定值之间的差的绝对值最小，所以我们需要定义一个变量diff用来记录差的绝对值，
然后我们还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，
然后用两个指针left和right来滑动寻找另外两个数，每确定两个数，我们求出此三数之和，
然后算和给定值的差的绝对值存在newDiff中，然后和diff比较并更新diff和结果closest即可，代码如下：
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(res - target);
        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        for (int i = 0; i < nums_size - 2; ++i) {
            int left = i + 1;
            int right = nums_size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int new_diff = abs(sum - target);
                if (diff > new_diff) { // 与目标之间的差距更小就更新
                    diff = new_diff;
                    res = sum;
                }
                sum < target ? ++left : --right;
            }
        }
        return res;
    }
};