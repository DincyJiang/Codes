// 集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。

// 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

// 示例 1:

// 输入: nums = [1,2,2,4]
// 输出: [2,3]
// 注意:

// 给定数组的长度范围是 [2, 10000]。
// 给定的数组是无序的。

#include <vector>

using namespace std;

// 统计每个数字出现的次数
class Solution1 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        int n = nums.size();
        vector<int> count(n, 0); // 出现次数
        for (int &num : nums) ++count[num-1];
        for (int i{0}; i < n; ++i) {
            if (res[0] != 0 && res[1] != 0) 
                return res;
            if (count[i] == 2) 
                res[0] = i+1;
            else if (count[i] == 0) 
                res[1] = i+1;
        }
        return res;
    }
};

// 把乱序的数字放在正确的位置上
// 数组有序后再遍历
class Solution2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for (int i{0}; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i{0}; i < n; ++i) {
            if (nums[i] != i+1)
                return {nums[i], i+1};
        }
    }
};