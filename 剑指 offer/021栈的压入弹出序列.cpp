// 题目描述
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
// 序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// （注意：这两个序列的长度是相等的）

//思路：压栈和出栈操作可能是交替进行的
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int sizea=pushV.size(),sizeb=popV.size();
        if(sizea==0 || sizeb==0 || sizea!=sizeb)
            return false;
        stack<int> st;
        int id=0;
        for(int i=0;i<sizea;i++)
        {
            while(st.empty() || st.top()!=popV[i]){
                st.push(pushV[id++]);
                if(id>sizea)
                    return false;
            }
            st.pop();
        }
    return st.empty() ? true : false;
    }
};