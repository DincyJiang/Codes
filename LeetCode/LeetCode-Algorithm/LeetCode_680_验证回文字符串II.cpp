// 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

// 示例 1:

// 输入: "aba"
// 输出: True
// 示例 2:

// 输入: "abca"
// 输出: True
// 解释: 你可以删除c字符。
// 注意:

// 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

#include <string>

using namespace std;

// 从两头向中间遍历，有两种情况：左边删掉，右边删掉
class Solution1 {
public:
    bool validPalindrome(string s) {
        int left{0};
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return isValid(s, left, right-1) || isValid(s, left+1, right);
            ++left;
            --right;
        }
        return true;
    }
    bool isValid(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};

class Solution2 {
public:
    bool validPalindrome(string s) {
        int left{0}; 
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                int l = left; // 第一种情况：把右边的删掉
                int r = right - 1;
                while (l < r) {
                    if (s[l] != s[r]) break; // 第一种情况失败，退出循环
                    ++l;
                    --r;
                    if (l >= r) return true;
                }
                ++left; // 第二种情况：把左边的删掉
                while (left < right) {
                    if (s[left] != s[right]) return false; // 两种情况都失败，直接返回false
                    ++left;
                    --right;
                }
            }
        }
        return true;
    }
};