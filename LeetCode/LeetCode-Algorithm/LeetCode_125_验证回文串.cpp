// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 示例 2:

// 输入: "race a car"
// 输出: false

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left{0};
        int right = s.size() - 1;
        while (left < right) {
            if (!judge(s[left])) ++left;
            else if (!judge(s[right])) --right;
            else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32) // 大写字母转为小写
                return false;
            else {
                ++left;
                --right;
            }
        }
        return true;
    }
    // 判断字符是否是数字或字母
    bool judge(const char& c) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        return false;
    }
};

// 在判断的时候就把大写改成小写
class Solution1 {
public:
    bool isPalindrome(string s) {
        int left{0};
        int right = s.size() - 1;
        while (left < right) {
            if (!judge(s[left])) ++left;
            else if (!judge(s[right])) --right;
            else if (s[left] != s[right]) return false;
            else {
                ++left;
                --right;
            }
        }
        return true;
    }
    // 判断字符是否是数字或字母，大写转换成小写
    bool judge(char& c) {
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') {
            c += 32;
            return true;
        }
        return false;
    }
};