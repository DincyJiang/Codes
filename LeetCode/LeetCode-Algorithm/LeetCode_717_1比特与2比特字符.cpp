// 有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。

// 现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。

// 示例 1:

// 输入: 
// bits = [1, 0, 0]
// 输出: True
// 解释: 
// 唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
// 示例 2:

// 输入: 
// bits = [1, 1, 1, 0]
// 输出: False
// 解释: 
// 唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
// 注意:

// 1 <= len(bits) <= 1000.
// bits[i] 总是0 或 1.

#include <vector>

using namespace std;

// 贪心算法，遍历到‘0’就只可能是字符‘0’，下标加一，遇到‘1’就加2，最后一定是到最后一个字符，不然就出错
class Solution1 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n-1) {
            if (bits[i] == 0) ++i;
            else i += 2;
        }
        return i == n-1;
    }
};

class Solution2 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n-1) {
            i += bits[i] + 1;
        }
        return i == n-1;
    }
};