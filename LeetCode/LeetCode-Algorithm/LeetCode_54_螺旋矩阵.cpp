// 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

// 示例 1:

// 输入:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// 输出: [1,2,3,6,9,8,7,4,5]
// 示例 2:

// 输入:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// 输出: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, btm = m - 1;
        vector<int> res;
        while (true) {
            // 左上角到右上角
            for (int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
            if (++top > btm) break;

            // 右上角向下第二个到右下角
            for (int i = top; i <= btm; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break;

            // 右下角向左第二个到左下角
            for (int i = right; i >= left; --i) res.push_back(matrix[btm][i]);
            if (--btm < top) break;
            
            // 左下角向上第二个到左上角向下第二个
            for (int i = btm; i >= top; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};