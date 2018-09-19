// 题目描述
// HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
// 今天测试组开完会后,他又发话了:在古老的一维模式识别中,
// 常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 你会不会被他忽悠住？(子向量的长度至少是1)

// 思路:
// 动态规划的主要思想就是保存中间计算结果


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//动态规划
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int res = array[0];
        int temp = res; // 临时和
        for (int i = 1; i < n; ++i) {
            temp += array[i];
            if (temp < array[i]) temp = array[i]; // 临时和是负值
            if (temp > res) res = temp;
        }
        return res;
    }
};
