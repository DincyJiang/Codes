/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 背包问题: 从n个物品中选择填满C容量的背包
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        if (sum%2 != 0) // 数组和必须是偶数
            return false;
        int C = sum / 2; //背包容量
        vector<bool> memo(C+1, false);
        for (int i = 0; i <= C; ++i)
            memo[i] = (nums[0] == i); // 看nums[0]能否填满背包
        for (int i = 1; i < n; ++i)
            for (int j = C; j >= nums[i]; --j)
                // memo[j]：不用第i个物品就能填满，memo[j-nums[i]]：用了第i个物品，看之前的能否填满
                memo[j] = memo[j] || memo[j-nums[i]];
        return memo[C];        
    }
};