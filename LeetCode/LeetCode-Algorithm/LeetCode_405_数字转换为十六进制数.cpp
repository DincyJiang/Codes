// 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

// 注意:

// 十六进制中所有字母(a-f)都必须是小写。
// 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
// 给定的数确保在32位有符号整数范围内。
// 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
// 示例 1：

// 输入:
// 26

// 输出:
// "1a"
// 示例 2：

// 输入:
// -1

// 输出:
// "ffffffff"

#include <string>

using std::string;

// 位操作
class Solution1 {
public:
    string toHex(int num) {
        string res{};
        for (int i = 0; num && i < 8; ++i) { // 循环终止的条件是num为0或者已经循环7次
            int t = num & 0xf; // 取出最右边四位
            if (t >= 10) 
                res = static_cast<char>('a' + t - 10) + res;
            else 
                res = static_cast<char>('0' + t) + res;
            num >>= 4; // num右移四位 
        }
        return res.empty() ? "0" : res;
    }
};

// 把要转换的十六进制数字字母先设好，按位置直接取
class Solution2 {
public:
    string toHex(int num) {
        string res{};
        string str{"0123456789abcdef"};
        int count{0};
        while (num != 0 && count++ < 8) {
            res = str[(num & 0xf)] + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};