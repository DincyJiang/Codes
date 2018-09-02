/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。
如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/

#include <vector>
#include <algorithm>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        int l = 0, r = -1;  // nums[l...r]为滑动窗口
        int res = size + 1;
        int sum = 0;
        while (l < size) {
            if (r+1 < size && sum < s) {
                ++r;
                sum += nums[r];
            } else {
                sum -= nums[l];
                ++l;
            }
            if (sum >= s) {
                res = min(res, r-l+1);
            }
        }
        if (res == size+1) return 0;
        return res;
    }
};