// 自除数 是指可以被它包含的每一位数除尽的数。

// 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。

// 还有，自除数不允许包含 0 。

// 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

// 示例 1：

// 输入： 
// 上边界left = 1, 下边界right = 22
// 输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// 注意：

// 每个输入参数的边界满足 1 <= left <= right <= 10000。

#include <vector>
#include <string>

using std::string;
using std::vector;
using std::to_string;

class Solution1 {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res{};
        for (int i = left; i <= right; ++i) {
            if (check(i)) res.push_back(i);
        }
        return res;
    }
    bool check(const int& num) {
        string s = to_string(num);
        for (char &c : s) {
            if (c == '0' || num % (c - '0')) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res{};
        for (int i = left, n{0}; i <= right; ++i) {
            for (n = i; n > 0; n /= 10) {
                if (n % 10 == 0 || i % ( n % 10) != 0) break;
            }
            if (n == 0) res.push_back(i);
        }
        return res;
    }
};