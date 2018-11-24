// 给定一个正整数，返回它在 Excel 表中相对应的列名称。

// 例如，

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...
// 示例 1:

// 输入: 1
// 输出: "A"
// 示例 2:

// 输入: 28
// 输出: "AB"
// 示例 3:

// 输入: 701
// 输出: "ZY"

#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res{};
        while (n) {
            if (n % 26 == 0) { // 能整除26的，直接在结果res上加上字符Z，然后n自减去26
                res += 'Z';
                n -= 26;
            } else {
                res += n % 26 - 1 + 'A'; // 对26取余，然后减去1，加上字符A
                n -= n % 26;
            }
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};