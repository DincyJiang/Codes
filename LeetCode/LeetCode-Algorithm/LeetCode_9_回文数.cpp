// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:

// 输入: 121
// 输出: true
// 示例 2:

// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 示例 3:

// 输入: 10
// 输出: false
// 解释: 从右向左读, 为 01 。因此它不是一个回文数。
// 进阶:

// 你能不将整数转为字符串来解决这个问题吗？

class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div{1};
        while ((x / div) >= 10) div *= 10;
        while (x > 0) {
            int left = x / div; // 最左边的数
            int right = x % 10; // 最右边的数
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int t{x};
        int ans{0};
        while (t) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return x == ans;
    }
};