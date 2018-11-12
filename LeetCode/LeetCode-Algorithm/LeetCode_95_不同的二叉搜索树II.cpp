// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

// 示例:

// 输入: 3
// 输出:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// 解释:
// 以上的输出对应以下 5 种不同结构的二叉搜索树：

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
这种建树问题一般来说都是用递归来解，这道题也不例外，划分左右子树，递归构造。
至于递归函数中为啥都用的是指针，若不用指针，全部实例化的话会存在大量的对象拷贝，要调用拷贝构造函数
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return *generateTreesDFS(1, n);
    }
    vector<TreeNode*> *generateTreesDFS(int start, int end) {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) subTree->push_back(nullptr);
        else {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> *leftSubTree = generateTreesDFS(start, i-1);
                vector<TreeNode*> *rightSubTree = generateTreesDFS(i+1, end);
                for (int j = 0; j < leftSubTree->size(); ++j) {
                    for (int k = 0; k < rightSubTree->size(); ++k) {
                        TreeNode *node = new TreeNode(i);
                        node->left = (*leftSubTree)[j];
                        node->right = (*rightSubTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};