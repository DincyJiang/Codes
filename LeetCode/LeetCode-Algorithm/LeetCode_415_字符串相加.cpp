// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

// 注意：

// num1 和num2 的长度都小于 5100.
// num1 和num2 都只包含数字 0-9.
// num1 和num2 都不包含任何前导零。
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

#include <string>

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res{};
        int m = num1.size();
        int n = num2.size();
        int i = m - 1; // 从最低位加
        int j = n - 1;
        int carry{0}; // 进位
        while (i >= 0 || j >= 0) {
            int a = (i >= 0 ? num1[i--] - '0' : 0);
            int b = (j >= 0 ? num2[j--] - '0' : 0);
            int sum = a + b + carry;
            carry = sum / 10; // 对10取余是进位
            res.insert(res.begin(), sum % 10 + '0');
        }
        return carry ? "1" + res : res;
    }
};