// 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

// 示例 1:

// 输入: "hello"
// 输出: "holle"
// 示例 2:

// 输入: "leetcode"
// 输出: "leotcede"
// 说明:
// 元音字母不包含字母"y"。

#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left{0};
        int right = s.size() - 1;
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) 
                swap(s[left++], s[right--]);
            else if (isVowel(s[left]))
                --right;
            else ++left;
        }
        return s;
    }
    bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            return true;
        }
        return false;
    }
};