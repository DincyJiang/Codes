// 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。

// 如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

// 现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

// 示例:
// 输入: 10
// 输出: 4
// 解释: 
// 在[1, 10]中有四个好数： 2, 5, 6, 9。
// 注意 1 和 10 不是好数, 因为他们在旋转之后不变。
// 注意:

// N 的取值范围是 [1, 10000]。

#include <string>
// #include <algorithm>

using std::to_string;
using std::string;

class Solution {
public:
    int rotatedDigits(int N) {
        int res{0};
        for (int i{1}; i <= N; ++i) {
            if (check(i)) ++res;
        }
        return res;
    }
    bool check(int k) {
        string str = to_string(k);
        bool flag = false;
        for (char c : str) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true; // 必须出现这四个数才能算
        }
        return flag;
    }
};