// 题目描述
// HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
// 今天测试组开完会后,他又发话了:在古老的一维模式识别中,
// 常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 你会不会被他忽悠住？(子向量的长度至少是1)

//思路:
//动态规划的主要思想就是保存中间计算结果
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//动态规划
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int result=array[0];
        int temp=array[0];
        for(int i=1;i<array.size();++i){
            //temp是之前计算的临时和，如果temp是负值，就从当前数开始重新计算，如果temp是正数，就可以加上当前数
            temp = (temp<0) ? array[i] : temp+array[i]; 
            result = (temp>result) ? temp : result;
        }
        return result;
    }
};
