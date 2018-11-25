// 编写一个程序，找出第 n 个丑数。

// 丑数就是只包含质因数 2, 3, 5 的正整数。

// 示例:

// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
// 说明:  

// 1 是丑数。
// n 不超过1690。

#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 7) return n;
        vector<int> res(n);
        res[0] = 1;
        int num_of_2{0};
        int num_of_3{0};
        int num_of_5{0};
        for (int i = 1; i < n; ++i) {
            res[i] = min(res[num_of_2] * 2, min(res[num_of_3] * 3, res[num_of_5] * 5));
            if (res[i] == res[num_of_2] * 2) ++num_of_2;
            if (res[i] == res[num_of_3] * 3) ++num_of_3;
            if (res[i] == res[num_of_5] * 5) ++num_of_5;
        }
        return res[n - 1];
    }
};