// 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

// 说明：不要使用任何内置的库函数，如  sqrt。

// 示例 1：

// 输入：16
// 输出：True
// 示例 2：

// 输入：14
// 输出：False

class Solution1 {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long x = num / 2;
        long t = x * x;
        while (t > num) {
            x /= 2;
            t = x * x;
        }
        for (int i = x; i <= 2 * x; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
};

// 二分查找法
class Solution2 {
public:
    bool isPerfectSquare(int num) {
        long left{0};
        long right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long t = mid * mid;
            if (t == num) return true;
            else if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

// 完全平方数是一系列奇数之和，例如：
// 1 = 1
// 4 = 1 + 3
// 9 = 1 + 3 + 5
// 16 = 1 + 3 + 5 + 7
class Solution3 {
public:
    bool isPerfectSquare(int num) {
        int i{1};
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};