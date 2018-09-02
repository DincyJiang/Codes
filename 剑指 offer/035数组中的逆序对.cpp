// 题目描述
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//思路：归并排序的思想
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()==0)
            return 0;
        long long res;
        vector<int> copy;
        for(auto num:data){
            copy.push_back(num);
        }
        int length=data.size();
        res=InversePairs(data,copy,0,length-1);
        return res%1000000007;
    }
    long long InversePairs(vector<int>& data,vector<int>& copy,int begin,int end){
        if(begin==end){
            copy[begin]=data[begin];
            return 0;
        }
        int length=(end-begin)>>2;
        long long left=InversePairs(copy,data,begin,begin+length);
        long long right=InversePairs(copy,data,begin+length+1,end);
        int i=begin+length;
        int j=end;
        int copyIndex=end;
        long long count=0;
        while(i>=begin&&j>=(begin+length+1)){
            if(data[i]>data[j]){
                copy[copyIndex--]=data[i--];
                count+=j-begin-length;
            }
            else
                copy[copyIndex--]=data[j--];
        }
        for(;i>=begin;i--)copy[copyIndex--]=data[i];
        for(;j>=begin+length+1;j--)copy[copyIndex--]=data[j];
        return left+right+count;
    }
};
