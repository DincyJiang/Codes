// 给定两个字符串, A 和 B。

// A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

// 示例 1:
// 输入: A = 'abcde', B = 'cdeab'
// 输出: true

// 示例 2:
// 输入: A = 'abcde', B = 'abced'
// 输出: false
// 注意：

// A 和 B 长度不超过 100。

#include <string>

using std::string;

class Solution1 {
public:
    bool rotateString(string A, string B) {
        int m = A.size();
        int n = B.size();
        if (m == 0 && n == 0) return true;
        if (m != n) return false;
        for (int i{0}; i < m; ++i) {
            if (A.substr(i, m-1) + A.substr(0, i) == B) return true;
        }
        return false;
    }
};

// 可以在A之后再加上一个A，这样如果新的字符串(A+A)中包含B的话，说明A一定能通过偏移得到B。
// 就比如题目中的例子，A="abcde", B="bcdea"，那么A+A="abcdeabcde"，里面是包括B的，所以返回true即可
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};