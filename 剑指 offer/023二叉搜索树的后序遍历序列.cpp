// 题目描述
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

//思路：后序遍历的顺序是，左右根
#include<vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence){
        return sequence.empty() ? false : judge(sequence,0,sequence.size()-1);
    }
private:
    bool judge(vector<int> sequence,int lhs,int rhs){
        if(lhs>=rhs)
            return true;
        int i=rhs;
        while(i>lhs && sequence[i-1]>sequence[rhs])//a[r]是最右边的数，也就是根 
            --i;               //i的位置现在是右子树最左的节点
        for(int j=i-1;j>=lhs;--j)//判断左子树中是否有比根大的数，如果有就返回false
            if(sequence[j]>sequence[rhs])
                return false;
        return judge(sequence,lhs,i-1) && judge(sequence,i,rhs-1);
    }
};