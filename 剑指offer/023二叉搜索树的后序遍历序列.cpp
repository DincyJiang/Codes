// 题目描述
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

//思路：后序遍历的顺序是，左右根
#include<vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        return n == 0 ? false : judge(sequence, 0, n - 1);
    }
private:
    bool judge(vector<int>& sequence, int l, int r) {
        if (l >= r) return true;
        // 最右边是根，先找到根的左孩子，i就是左孩子节点
        int i = r - 1;
        while (i > l && sequence[i] > sequence[r])
            --i;
        // 左子树中不能有比根大的
        for (int j = i - 1; j >= l; --j)
            if (sequence[j] > sequence[r])
                return false;
        return judge(sequence, l, i) &&
               judge(sequence, i+1, r-1);
    }
};