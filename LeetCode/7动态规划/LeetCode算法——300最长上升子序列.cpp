/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 时间复杂度O(n^2)
// 维护一个一维dp数组，其中dp[i]表示以nums[i]为结尾的最长递增子串的长度，
// 对于每一个nums[i]，我们从第一个数再搜索到i，如果发现某个数小于nums[i]，
// 我们更新dp[i]，更新方法为dp[i] = max(dp[i], dp[j] + 1)，
// 即比较当前dp[i]的值和那个小于num[i]的数的dp值加1的大小，
// 我们就这样不断的更新dp数组，到最后dp数组中最大的值就是我们要返回的LIS的长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 时间复杂度O(nlogn)
// 二分查找法，思路是先建立一个空的dp数组，然后开始遍历原数组，
// 对于每一个遍历到的数字，我们用二分查找法在dp数组找第一个不小于它的数字，
// 如果这个数字不存在，那么直接在dp数组后面加上遍历到的数字，
// 如果存在，则将这个数字更新为当前遍历到的数字，最后返回dp数字的长度即可，
// 注意的是，跟上面的方法一样，特别注意的是dp数组的值可能不是一个真实的LIS。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int left = 0, right = dp.size();
            // 二分查找法在dp数组找第一个不小于它的数字
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            if (right >= dp.size()) // 如果这个数字不存在，那么直接在dp数组后面加上遍历到的数字
                dp.push_back(nums[i]);
            else // 如果存在，则将这个数字更新为当前遍历到的数字
                dp[right] = nums[i];
        }
        return dp.size();
    }
};