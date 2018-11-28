// 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3
// 输出:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int top = 0, btm = n - 1, left = 0, right = n - 1;
        int val = 1;
        while (true) {
            for (int i = left; i <= right; ++i) res[top][i] = val++;
            if (++top > btm) break;

            for (int i = top; i <= btm; ++i) res[i][right] = val++;
            if (--right < left) break;

            for (int i = right; i >= left; --i) res[btm][i] = val++;
            if (--btm < top) break;

            for (int i = btm; i >= top; --i) res[i][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};