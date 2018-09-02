// 题目描述
// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//代码一：利用泛型算法sort
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (input.empty() || input.size() < k) return result;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; ++i) {
            result.push_back(input[i]);
        }
        return result;
    }
};

//代码二：利用最大堆
class Solution2{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input,int k){
        int len=input.size();
        vector<int> result;
        if(len<=0 || k>len || k<=0)
            return result;
        for(int i=0;i<k;++i)
            result.push_back(input[i]); //result中最开始存入前k个数
        make_heap(result.begin(),result.end()); //建最大堆
        for(int i=k;i<len;++i){
            if(input[i]<result[0]){ //对后面的数，如果有比堆中最大的数小的就压入堆中
                pop_heap(result.begin(),result.end());
                result.pop_back();
                result.push_back(input[i]);
                push_heap(result.begin(),result.end());
            }
        }
        sort_heap(result.begin(),result.end());
        return result;
    }
};
