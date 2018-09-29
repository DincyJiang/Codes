// 题目描述
// 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
// 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
// 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
// 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
// 请问该机器人能够达到多少个格子？


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = moving(threshold, rows, cols, 0, 0, visited);
        return count;
    }
private:
    int moving(int threshold, int& rows, int& cols, int i, int j, vector<vector<bool>>& visited) {
        int count = 0;
        if (i >= 0 && i < rows &&
            j >= 0 && j < cols &&
            sum(i) + sum(j) <= threshold &&
            visited[i][j] == false) {
            visited[i][j] = true;
            count = 1 + moving(threshold, rows, cols, i+1, j, visited)
                      + moving(threshold, rows, cols, i-1, j, visited)
                      + moving(threshold, rows, cols, i, j-1, visited)
                      + moving(threshold, rows, cols, i, j+1, visited);
        }
        return count;
    }
    int sum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
};