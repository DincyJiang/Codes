// 题目描述
// 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
// 要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：
class Solution {
public:
    int StrToInt(string str) {
        int n = str.length();
        if (!n) return 0;
        int s = 1;
        long long res = 0;
        if (str[0] == '-') s = -1;
        for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; ++i) {
            if (!('0' <= str[i] && str[i] <='9')) return 0;
            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        }
        return res * s;
    }
};

class Solution {
public:
    int StrToInt(string str) {
        int len=str.length();
        if(len==0)
            return 0;
        int dig=true;
        int i=0;
        int num=0;
        //滤掉前面的空格
        while(str[i]==' '){
            i++;
        }
        //进行符号判断
        if(str[i]=='+'){
            i++;
        }else if(str[i]=='-'){
            i++;
            dig*=false;
        }
        while(str[i]!='\0'){
            //对字符进行是否为数字的判断
            if(str[i]>='0'&&str[i]<='9'){
                int flag=dig?1:-1;
                num=num*10+flag*(str[i]-'0');
                //对数字是否溢出进行判断
            //    if((dig && num>0x7FFFFFFF)||(dig== && num<(signed int)0x80000000)){
            //        num=0;
            //        break;
            //    }
                i++;
            }else{
                num=0;
                break;
            }
             
        }
        return num;
    }
};