/*
给定一棵二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义： “对于有根树T的两个结点u、v，最近公共祖先表示一个结点x，满足x是u、v的祖先且x的深度尽可能大。”（一个节点也可以是它自己的祖先）

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
例如，节点5和节点1的最近公共祖先是节点3；节点5和节点4的最近公共祖先是节点5，因为根据定义，一个节点可以是它自己的祖先。
*/

/*
思路：
求p节点路径，q节点路径，两路径上最后一个相同的节点
从根结点遍历至该节点，找到该节点后就结束搜索
将遍历过程中遇到的节点按顺序存储起来，这些节点就是路径节点
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<assert.h>
// using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;
        std::vector<TreeNode*> node_p_path;
        std::vector<TreeNode*> node_q_path;
        int finish=0;
        preOrder(root,p,path,node_p_path,finish);
        path.clear();
        finish=0;
        preOrder(root,q,path,node_q_path,finish);
        int path_len=0; //较短路径的长度
        if(node_p_path.size()<node_q_path.size()){
            path_len=node_p_path.size();
        }
        else{
            path_len=node_q_path.size();
        }
        TreeNode *result=0;
        for(int i=0;i<path_len;++i){
            if(node_p_path[i]==node_q_path[i]){
                result=node_p_path[i];
            }
        }
        return result;
    }
private:
    void preOrder(TreeNode *node, //正在遍历的节点
                TreeNode *search, //待搜索的节点
                std::vector<TreeNode*> &path, //遍历时的节点路径栈
                std::vector<TreeNode*> &result, //最终搜索到节点search的路径结果
                int &finish){ //记录是否找到节点search的变量，未找到是0
        if(!node || finish){
            return;
        }
        path.push_back(node);
        if(node==search){
            finish=1;
            result=path;
        }
        preOrder(node->left,search,path,result,finish);
        preOrder(node->right,search,path,result,finish);
        path.pop_back();
    }
};

int main(){
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left=&b;
    a.right=&c;
    b.left=&d;
    c.left=&e;
    c.right=&f;
    d.left=&g;
    d.right=&h;
    f.left=&x;
    f.right=&y;
    Solution solve;
    TreeNode *result=solve.lowestCommonAncestor(&a,&b,&f);
    std::cout<<result->val;
    return 0;
}

/* 思路二：使用递归解法
1.若p和q分别位于左右子树中，那么对左右子结点调用递归函数，会分别返回p和q结点的位置，
  而当前结点正好就是p和q的最小共同父结点，直接返回当前结点即可;
2.若p和q同时位于左子树，这里有两种情况:
  一种情况是left会返回p和q中较高的那个位置，而right会返回空，所以我们最终返回非空的left即可,
  还有一种情况是left会返回p和q的最小父结点，就是说当前结点的左子树中的某个结点才是p和q的最小父结点，会被返回;
3.若p和q同时位于右子树，同样这里有两种情况:
  一种情况是right会返回p和q中较高的那个位置，而left会返回空，所以我们最终返回非空的right即可，
  还有一种情况是会返回p和q的最小父结点，就是说当前结点的右子树中的某个结点才是p和q的最小父结点，会被返回，写法很简洁
  */
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
       if (left && right) return root;
       return left ? left : right;
    }
};

/*
上述代码可以进行优化一下，如果当前结点不为空，且既不是p也不是q，那么根据上面的分析，p和q的位置就有三种情况，
p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树。
我们需要优化的情况就是当p和q同时为于左子树或右子树中，而且返回的结点并不是p或q，
那么就是p和q的最小父结点了，已经求出来了，就不用再对右结点调用递归函数了，
同样，对返回的right也做同样的优化处理
*/
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       if (left && left != p && left != q) return left;
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
       if (right && right != p && right != q) return right;
       if (left && right) return root;
       return left ? left : right;
    }
};


