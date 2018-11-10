// 题目描述
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
// 例如，如果输入如下矩阵： 
// 1   2   3   4 
// 5   6   7   8 
// 9   10  11  12 
// 13  14  15  16 
// 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

// 思路：上下左右四个哨兵

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();    // 行数
        int col = matrix[0].size(); // 列数
        vector<int> res;
        if (row == 0 || col == 0)
            return res;
        int left = 0, right = col - 1, top = 0, btm = row - 1;
        while (left <= right && top <= btm) {
            // 左上角到右上角
            for (int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            // 右上角向下第二个到右下角
            if (top < btm) // 排除只有一行的情况
                for (int i = top+1; i <= btm; ++i)
                    res.push_back(matrix[i][right]);
            // 右下角向左第二个到左下角
            if (left < right && top < btm)
                for (int i = right-1; i >= left; --i)
                    res.push_back(matrix[btm][i]);
            // 左下角向上第二个到左上角向下第二个
            if (top+1 < btm && left < right)
                for (int i = btm-1; i >= top+1; --i)
                    res.push_back(matrix[i][left]);
            ++left, --right, ++top, --btm;
        }
        return res;
    }
};



