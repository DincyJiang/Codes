/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include <vector>
#include <algorithm>
using namespace std;

// 这里允许最多重复的次数是两次，那么我们就需要用一个变量count来记录还允许有几次重复，
// count初始化为1，如果出现过一次重复，则count递减1，
// 那么下次再出现重复，快指针直接前进一步，
// 如果这时候不是重复的，则count恢复1，由于整个数组是有序的，
// 所以一旦出现不重复的数，则一定比这个数大，此数之后不会再有重复项。                              
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int pre = 0, cur = 1;
        int count = 1; // 还能重复的字符个数
        while (cur < n) {
            if (nums[pre] == nums[cur] && count == 0)
                ++cur;
            else {
                if (nums[pre] == nums[cur])
                    --count;
                else
                    count = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return pre + 1;
    }
};

