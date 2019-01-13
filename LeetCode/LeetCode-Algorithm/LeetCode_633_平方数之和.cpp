// 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

// 示例1:

// 输入: 5
// 输出: True
// 解释: 1 * 1 + 2 * 2 = 5
 

// 示例2:

// 输入: 3
// 输出: False

#include <cmath>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    bool judgeSquareSum(int c) {
        for (int i = sqrt(c); i >= 0; --i) {
            if (i*i == c) return true; // i和0，0也是整数
            int d = c - i*i;
            int t = sqrt(d);
            if (t*t == d) return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> s{};
        for (int i{0}; i <= sqrt(c); ++i) {
            s.insert(i*i);
            if (s.count(c - i*i)) return true;
        }
        return false;
    }
};

// 高效
// 二分算法
class Solution3 {
public:
    bool judgeSquareSum(int c) {
        int a{0};
        int b = sqrt(c);
        while (a <= b) {
            if (a*a + b*b == c)
                return true;
            else if (a*a + b*b < c)
                ++a;
            else
                --b;
        }
        return false;
    }
};