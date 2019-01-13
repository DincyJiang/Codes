// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

// 示例 1:

// 输入: "Let's take LeetCode contest"
// 输出: "s'teL ekat edoCteeL tsetnoc" 
// 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    string reverseWords(string s) {
        string res{};
        string t{};
        stringstream ss{s};
        while (ss >> t) {
            reverse(t.begin(), t.end()); // 反转字符串
            res += t + ' ';
        }
        res.pop_back(); // 把最后的空格删掉
        return res;
    }
};

// 不使用字符流函数，使用双指针，对范围内单词进行交换
class Solution2 {
public:
    string reverseWords(string s) {
        int beg{};
        int end{};
        int n = s.size();
        while (beg < n && end < n) {
            while (end < n && s[end] != ' ') ++end;
            for (int i = beg, j = end-1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            beg = ++end;
        }
        return s;
    }
};