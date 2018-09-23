// 题目描述
// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
// 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 思路：
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        if (n == 0) return vector<int>();
        vector<int> B(n);
        B[0] = 1;
        // 计算下三角连乘
        for (int i = 0; i < n - 1; ++i)
            B[i+1] = B[i] * A[i];
        // 计算上三角连乘
        int t = 1;
        for (int i = n - 1; i >= 0; --i) {
            B[i] *= t;
            t *= A[i];
        }
        return B;
    }
};