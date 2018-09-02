/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 0) return 0;
        vector<int> memo(n+1, -1); // memo[i]表示将数字i分割（至少分割成两部分）后得到的最大乘积
        memo[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i-1; ++j)
                memo[i] = max3(j*memo[i-j], j*(i-j), memo[i]);
                // 三种结果取其大者，分别是：1：j和之前的分割部分相乘； 
                //                        2：i只分两部分，j和i-j； 
                //                        3：memo[i]自身的值
        return memo[n];
    }
private:
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
};