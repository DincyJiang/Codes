// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba"也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"


#include <string>

using namespace std;

/*
维护一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，当i = j时，只有一个字符，肯定是回文串，如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即i - j >= 2时，除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串，通过以上分析，可以写出递推式如下：

dp[i, j] = 1                                   if i == j

         = s[i] == s[j]                        if j = i + 1

         = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1 
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        bool dp[n][n] = {false};
        int left = 0, right = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j+1][i-1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = true;
        }
        return s.substr(left, right - left + 1);
    }
};