// 题目描述
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 思路：双指针，从两头向中间走
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int n = array.size();
        int p = 0, q = n-1;
        while (p < q) {
            int m = array[p] + array[q]; // 当前的和
            if (m < sum) ++p;
            if (m > sum) --q;
            if (m == sum) // 两端第一次遇到的两个和为S的数字，乘积就是最小的
                return vector<int> {array[p], array[q]};
        }
        return vector<int> ();
    }
};