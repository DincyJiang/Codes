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
        int size = A.size();
        vector<int> B;
        if (size == 0) return B;
        B.push_back(1);
        for (int i = 0; i < size - 1; ++i) {
            B.push_back(B.back() * A[i]);
        }
        int tmp = 1;
        for (int i = size - 1; i >= 0; --i) {
            B[i] *= tmp;
            tmp *= A[i];
        }
        return B;
    }
};