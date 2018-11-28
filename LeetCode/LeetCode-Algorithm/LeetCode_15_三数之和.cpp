// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
#include <vector>

using namespace std;

/*
我们对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。
这里我们可以先做个剪枝优化，就是当遍历到正数的时候就break，为啥呢，因为我们的数组现在是有序的了，
如果第一个要fix的数就是正数了，那么后面的数字就都是正数，就永远不会出现和为0的情况了。
然后我们还要加上重复就跳过的处理，处理方法是从第二个数开始，如果和前面的数字相等，就跳过，
因为我们不想把相同的数字fix两次。对于遍历到的数，用0减去这个fix的数得到一个target，
然后只需要再之后找到两个数之和等于target即可。我们用两个指针分别指向fix数字之后开始的数组首尾两个数，
如果两个数和正好为target，则将这两个数和fix的数一起存入结果中。然后就是跳过重复数字的步骤了，
两个指针都需要检测重复数字。如果两数之和小于target，则我们将左边那个指针i右移一位，使得指向的数字增大一些。
同理，如果两数之和大于target，则我们将右边那个指针j左移一位，使得指向的数字减小一些，代码如下：
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return res;
        int nums_size = nums.size();
        for (int k = 0; k < nums_size; ++k) {
            if (nums[k] > 0) break; // 遍历到正数就停止
            if (k > 0 && nums[k] == nums[k-1]) continue; // 跳过重复值
            int target = 0 - nums[k]; // 目标值是当前找到的值的相反数
            int i = k+1;
            int j = nums_size - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i+1]) ++i; // 左边遇到重复值跳过
                    while (i < j && nums[j] == nums[j-1]) --j; // 右边遇到重复值跳过
                    ++i;
                    --j;
                } else if (nums[i] + nums[j] < target) {
                    ++i;
                } else {
                    --j;
                }
            }
        }
        return res;
    }
};