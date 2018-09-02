// 题目描述
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include<iostream>
#include<vector>

using namespace std;


// 采用阵地攻守的思想：
// 第一个数字作为第一个士兵，守阵地；count = 1；
// 遇到相同元素，count++;
// 遇到不相同元素，即为敌人，同归于尽,count--；
// 当遇到count为0的情况，又以新的i值作为守阵地的士兵，继续下去，
// 到最后还留在阵地上的士兵，有可能是主元素。
// 再加一次循环，记录这个士兵的个数看是否大于数组一般即可。

//代码一：时间复杂度O(n)
class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        int n=numbers.size();
        if(n==0) return 0;
        int num=numbers[0],count=1;
        for(int i=1;i<n;i++){
            if(numbers[i]==num) ++count;
            else --count;
            if(count==0){
                num=numbers[i];
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(numbers[i]==num) ++count;  //现在的num就是剩下的最后的数字
        }
        if(count*2 > n)
            return num;
        else
            return 0;
    }
};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int size = numbers.size();
        int num = numbers[0];
        int count = 1;
        for (int i = 1; i < size; ++i) {
            if (numbers[i] != num) {
                --count;
            } else {
                ++count;
            }
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        count = 0;
        for (int i = 0; i < size; ++i) {
            if (num == numbers[i]) ++count;
        }
        return count * 2 > size ? num : 0;
    }
};