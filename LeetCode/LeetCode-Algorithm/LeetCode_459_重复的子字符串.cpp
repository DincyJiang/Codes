// 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

// 示例 1:

// 输入: "abab"

// 输出: True

// 解释: 可由子字符串 "ab" 重复两次构成。
// 示例 2:

// 输入: "aba"

// 输出: False
// 示例 3:

// 输入: "abcabcabcabc"

// 输出: True

// 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = n / 2; i >= 1; --i) { // 子串长度不能大于总长度的一半
            if (n % i == 0) { // 子串长度要能被总长度整除
                int c = n / i; // 原字符串分成c段
                string t{};
                for (int j{0}; j < c; ++j)
                    t += s.substr(0, i); // 拼接c段子串
                if (t == s)
                    return true; // 只要有一种情况符合就可以
            }
        }
        return false;
    }
};

// KMP
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        int i{1};
        int j{0};
        int n = s.size();
        vector<int> dp(n+1, 0);
        while (i < n) {
            if (s[i] == s[j]) 
                dp[++i] = ++j;
            else if (j == 0) 
                ++i;
            else 
                j = dp[j];
        }
        return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
};