// 题目描述
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include<iostream>
#include<vector>
#include <map>
using namespace std;


// 采用阵地攻守的思想：
// 第一个数字作为第一个士兵，守阵地；count = 1；
// 遇到相同元素，count++;
// 遇到不相同元素，即为敌人，同归于尽,count--；
// 当遇到count为0的情况，又以新的i值作为守阵地的士兵，继续下去，
// 到最后还留在阵地上的士兵，有可能是主元素。
// 再加一次循环，记录这个士兵的个数看是否大于数组一般即可。

//代码一：时间复杂度O(n)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if (n == 0) return 0;
        int cur = numbers[0]; // 当前值，可能是最终结果值
        int count = 1;      // 当前值的数量
        for (int i = 0; i < n; ++i) {
            if (numbers[i] != cur) // 遍历到的值和当前值不同
                --count;
            else
                ++count;
            if (count == 0) {      // 当前值的数量是0，就更新当前值
                cur = numbers[i];
                count = 1;
            }
        }
        // 判断当前值的数量是否大于n/2
        count = 0;
        for (int i = 0; i < n; ++i)
            if (numbers[i] == cur)
                ++count;
        return count > n/2 ? cur : 0;
    }
};

class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        map<int, int> m;
        for (int i : numbers)
            ++m[i];
        for (auto i : m)
            if (i.second > n/2)
                return i.first;
        return 0;
    }
};