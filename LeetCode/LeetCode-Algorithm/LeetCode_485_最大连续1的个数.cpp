// 给定一个二进制数组， 计算其中最大连续1的个数。

// 示例 1:

// 输入: [1,1,0,1,1,1]
// 输出: 3
// 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
// 注意：

// 输入的数组只包含 0 和1。
// 输入数组的长度是正整数，且不超过 10,000。

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res{0};
        int count{0};
        for (int &num : nums) {
            count = (num == 0 ? 0 : count + 1); // 当前数是0，计数就清0
            res = max(res, count);
        }
        return res;
    }
};

class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res{0};
        int sum{0};
        for (int &num : nums) {
            sum = (sum + num) * num; // 乘积就是当前连续1的个数，遇到0时就为0
            res = max(res, sum);
        }
        return res;
    }
};