/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，
使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。
所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

#include <vector>
#include <unordered_map>
using namespace std;

// n <= 500, 数据规模500，可以用O(n2)的算法
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record;
        // 把C和D中的每一种可能放入查找表中
        for (auto i = C.begin(); i != C.end(); ++i)
            for (auto j = D.begin(); j != D.end(); ++j)
                record[*i + *j]++;
        int res = 0;
        for (auto i = A.begin(); i != A.end(); ++i)
            for (auto j = B.begin(); j != B.end(); ++j)
                if (record.find(- *i - *j) != record.end())
                    res += record[- *i - *j];
        return res;
    }
}; 