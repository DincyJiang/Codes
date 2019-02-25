// 给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

// 重复出现的子串要计算它们出现的次数。

// 示例 1 :

// 输入: "00110011"
// 输出: 6
// 解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

// 请注意，一些重复出现的子串要计算它们出现的次数。

// 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
// 示例 2 :

// 输入: "10101"
// 输出: 4
// 解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
// 注意：

// s.length 在1到50,000之间。
// s 只包含“0”或“1”字符。

#include <string>

using namespace std;

// 分别统计0和1的个数
class Solution1 {
public:
    int countBinarySubstrings(string s) {
        int zeros{0};
        int ones{0};
        int res{0};
        for (int i{0}; i < s.size(); ++i) {
            if (i == 0) {
                (s[i] == '1') ? ++ones : ++zeros;
            } else {
                if (s[i] == '1') {
                    ones = (s[i-1] == '1') ? ones+1 : 1;
                    if (zeros >= ones) ++res;
                } else if (s[i] == '0') {
                    zeros = (s[i-1] == '0') ? zeros+1 : 1;
                    if (ones >= zeros) ++res;
                }
            }
        }
        return res;
    }
};

// pre和cur可以在0和1之间切换
class Solution2 {
public:
    int countBinarySubstrings(string s) {
        int res{0};
        int pre{0};
        int cur{1};
        int n = s.size();
        for (int i{1}; i < n; ++i) {
            if (s[i] == s[i-1])
                ++cur;
            else {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur) ++res;
        }
        return res;
    }
};