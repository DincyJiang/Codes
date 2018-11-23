// 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

// 如果不存在最后一个单词，请返回 0 。

// 说明：一个单词是指由字母组成，但不包含任何空格的字符串。

// 示例:

// 输入: "Hello World"
// 输出: 5

#include <string>

using namespace std;

class Solution1 {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int index = n-1; // 从尾部开始向前遍历
        while (index >= 0 && s[index] == ' ') --index;
        int res{0};
        while (index >= 0 && s[index--] != ' ') ++res;
        return res;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res{0};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') { 
                if (i != 0 && s[i-1] == ' ') // 判断前面一个位置的字符是否为空格
                    res = 1; 
                else ++res;
            }
        }
        return res;
    }
};