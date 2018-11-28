// 编写一个函数，其作用是将输入的字符串反转过来。

// 示例 1:

// 输入: "hello"
// 输出: "olleh"
// 示例 2:

// 输入: "A man, a plan, a canal: Panama"
// 输出: "amanaP :lanac a ,nalp a ,nam A"

#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int left{0};
        int right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
        return s;
    }
};