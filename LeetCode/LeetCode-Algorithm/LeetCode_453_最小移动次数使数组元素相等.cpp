// 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。

// 示例:

// 输入:
// [1,2,3]

// 输出:
// 3

// 解释:
// 只需要3次移动（注意每次移动会增加两个元素的值）：

// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

#include <vector>
#include <algorithm>

using std::min;
using std::vector;

// 每次移动使 n - 1 个元素增加1，就相当于剩下的那 1 个元素减去1
// 最终移动次数就相当于 所有数字向 最小值 移动的次数
class Solution1 {
public:
    int minMoves(vector<int>& nums) {
        int min_num = INT_MAX;
        int res{0};
        for (int num : nums)
            min_num = min(min_num, num); // 找到最小值
        for (int num : nums)
            res += num - min_num; // 累计所有数字与最小值的差
        return res;
    }
};

// 原理同解法1，求法可以用所有数字和 减去 最小值*元素个数
class Solution2 {
public:
    int minMoves(vector<int>& nums) {
        int min_num = INT_MAX;
        int res{0};
        int sum{0};
        for (int num : nums) {
            min_num = min(min_num, num);
            sum += num;
        }
        return sum - nums.size() * min_num;
    }
};