// 题目描述
// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 思路：先排序，排序的规则按照两个数拼接起来的
// 对vector容器内的数据进行排序，按照 将a和b转为string后
// 若 a＋b<b+a  a排在在前 的规则排序,
// 如 2 21 因为 212 < 221 所以 排序后为 21 2 
// o_string() 可以将int 转化为string

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size()==0) return "";
        sort(numbers.begin(),numbers.end(),cmp); //cmp是自制的比较谓词，可以改变sort的默认排序方法
        string result;
        for(auto i : numbers){
            result+=to_string(i);
        }
        return result;
    }
    static bool cmp(int a,int b){
        string A=to_string(a)+to_string(b); //to_string(a)将参数a转换成字符
        string B=to_string(b)+to_string(a);
        return A<B; //string的比较是按照字典序的比较
    }
};