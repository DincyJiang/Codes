/*
只有0-9，和加减乘除四种运算符，加减优先级高于乘除，计算表达式结果
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> op;
stack<int> num;

int chartoint(char c){//字符转数字
    return c-48;
}
int isoperate(char c){
    /*
    判断字符是数字还是操作符
    操作符：返回1
    数字：返回0
    */
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return 1;
    else return 0;
}
int priori(char c){
    /*
    判断一个字符的优先级，返回的是它的优先级
    */
    if(c=='*'||c=='/') return 1;
    if(c=='+'||c=='-') return 2;
}
int iswhatandcompute(char c,int n1, int n2){
    /*
    c:操作符
    n1,n2:操作数
    返回的是n2 c n1 的值
    */
    if (c=='*') return n1*n2;
    if (c=='/') return n2/n1;
    if (c=='+') return n2+n1;
    if (c=='-') return n2-n1;
}
void compute(string s){//计算表达式的值
    int i;
    int size_s=s.size();
    for(i=0;i<size_s;){
        if (isoperate(s[i])){//判断s[i]是操作符
            if(!op.empty()){//操作符栈非空
                char temp=op.top();
                if(priori(temp)>=priori(s[i])){
                    int n1=num.top();num.pop();
                    int n2=num.top();num.pop();
                    int n3=iswhatandcompute(temp,n1,n2);
                    num.push(n3);
                    op.pop();
                    op.push(s[i]);
                    i++;
                }
                else{
                    op.push(s[i]);i++;
                }
            }
            else
                {op.push(s[i]); i++;}
        }
        else{//是数字
            int n=chartoint(s[i]);
            num.push(n);i++;
        }
    }
    while(!op.empty()){
        int t=op.top();op.pop();
        int t1=num.top();num.pop();
        int t2=num.top();num.pop();
        int t3=iswhatandcompute(t,t1,t2);
        num.push(t3);
    }
    int n=num.top();
    cout<<n<<endl;
}
int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    compute(str);
    return 0;
}