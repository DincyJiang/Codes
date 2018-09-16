/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
*/

#include <vector>
#include <queue>
using namespace std;

// 时间复杂度：O(m*n)
// 当前行的最后一个元素并不一定会小于下一行的首元素，
// 所以我们并不能直接定位第K小的元素，所以只能另辟蹊径。
// 先来看一种利用堆的方法，我们使用一个最大堆，然后遍历数组每一个元素，
// 将其加入堆，根据最大堆的性质，大的元素会排到最前面，
// 然后我们看当前堆中的元素个数是否大于k，大于的话就将首元素去掉，
// 循环结束后我们返回堆中的首元素即为所求:
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q; // 默认大根堆
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace(matrix[i][j]);
                if (q.size() > k) // 堆中维持k个
                    q.pop();
            }
        }
        return q.top();
    }
};

