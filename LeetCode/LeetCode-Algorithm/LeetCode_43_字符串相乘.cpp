// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
// 说明：

// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

#include <string>
#include <vector>

using namespace std;

/*
多位数的乘法过程，每位相乘然后错位相加
把错位相加后的结果保存到一个一维数组中，然后分别每位上算进位，最后每个数字都变成一位，
然后要做的是去除掉首位0，最后把每位上的数字按顺序保存到结果中即可，代码如下：
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res{};
        int n1 = num1.size();
        int n2 = num2.size();
        int k = n1 + n2 - 2;
        int carry{0};              // 进位
        vector<int> v(n1 + n2, 0); // n1位数乘以n2位数的结果最多是n1+n2位
        for (int i{0}; i < n1; ++i) {
            for (int j{0}; j < n2; ++j) {
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        // 依次计算每一位的进位
        for (int i{0}; i < n1 + n2; ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        // 去除前面的0
        int i = n1 + n2 - 1;
        while (v[i] == 0)
            --i;
        if (i < 0)
            return "0";
        while (i >= 0)
            res.push_back(v[i--] + '0');
        return res;
    }
};