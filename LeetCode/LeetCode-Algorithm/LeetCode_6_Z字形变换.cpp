// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

// 请你实现这个将字符串进行指定行数变换的函数：

// string convert(string s, int numRows);
// 示例 1:

// 输入: s = "LEETCODEISHIRING", numRows = 3
// 输出: "LCIRETOESIIGEDHN"
// 示例 2:

// 输入: s = "LEETCODEISHIRING", numRows = 4
// 输出: "LDREOEIIECIHNTSG"
// 解释:

// L     D     R
// E   O E   I I
// E C   I H   N
// T     S     G

#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res{};
        int sz = s.size();
        int differ = 2 * numRows - 2;
        for (int i{0}; i < numRows; ++i) {
            for (int j = i; j < sz; j += differ) {
                res += s[j];
                int tmp = j + differ - 2*i; // 斜的字符
                if (i != 0 && i != numRows - 1 && tmp < sz)
                    res += s[tmp];
            }
        }
        return res;
    }
};

// 额外空间，方向
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> rows(min(numRows, static_cast<int>(s.size())));
        int curRow{0};
        bool goDown{false}; // 方向，初始化为向上
        for (char &c : s) {
            if (curRow == 0 || curRow == numRows - 1)
                goDown = !goDown; // 方向改变
            rows[curRow] += c;
            curRow += goDown ? 1 : -1;
        }
        string res{};
        for (string &row : rows)
            res += row;
        return res;
    }
};