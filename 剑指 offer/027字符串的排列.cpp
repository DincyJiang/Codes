// 题目描述
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。


/*
思路：
n个元素的全排列=n-1个元素全排列 + 1个元素作为前缀
出口：如果只有一个元素的全排列，说明已经排完，则输出
不断将每个元素放在第一个元素，其余元素进行全排列
*/
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//代码一：
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.size()==0){
            return result;
        }
        Permutation(result,str,0);
        sort(result.begin(),result.end()); //按字典序排列最终的结果
        return result;
    }
    //遍历第begin位的所有可能性
    void Permutation(vector<string>& result,string str,int begin){
        if(begin==str.size()-1){
            result.push_back(str);
        }
        for(int i=begin;i<str.size();i++){
            if(i!=begin && str[i]==str[begin]){ //如果有重复的字符，跳过本次循环，进入下一循环
                continue;
            }
            swap(str[i],str[begin]); //使得begin位取得不同的可能字符
            Permutation(result,str,begin+1); //遍历后面的字符
            //swap(str[i],str[begin]); //将begin处的元素换回来，防止重复发生
        }
    }
};

//代码二：
class Solution2{
public:
    vector<string> Permutation(string str){
        sort(str.begin(),str.end());//先把输入的原始字符串按照字典序排列
        vector<string> result;
        Permutation(result,str,0);
        return result;
    }
    void Permutation(vector<string>& result,string str,int begin){
        if(begin==str.size()-1){
            result.push_back(str);
        }
        for(int i=begin;i<str.size();i++){
            if(i!=begin && str[i]==str[begin]){ //如果有重复的字符，跳过本次循环，进入下一循环
                continue;
            }
            swap(str[i],str[begin]); //使得begin位取得不同的可能字符
            Permutation(result,str,begin+1); //遍历后面的字符
        }
    }
};

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.empty()) return result;
        Permutation(result, str, 0);
        sort(result.begin(), result.end());
        return result;
    }
    void Permutation(vector<string>& result, string str, int begin) {
        if (begin == str.size() - 1) result.push_back(str);
        for (int i = begin; i < str.size(); ++i) {
            if (i != begin && str[i] == str[begin]) continue;
            swap(str[i], str[begin]);
            Permutation(result, str, begin + 1);
            swap(str[i], str[begin]);
        }
    }
};