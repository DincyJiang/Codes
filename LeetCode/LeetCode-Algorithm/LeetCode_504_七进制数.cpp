// 给定一个整数，将其转化为7进制，并以字符串形式输出。

// 示例 1:

// 输入: 100
// 输出: "202"
// 示例 2:

// 输入: -7
// 输出: "-10"
// 注意: 输入范围是 [-1e7, 1e7] 。

#include <string>

using std::string;
using std::to_string;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res{};
        bool positive = num > 0; // 正负号
        while (num != 0) {
            res = to_string(abs(num % 7)) + res;
            num /= 7;
        }
        return positive ? res : "-" + res;
    }
};