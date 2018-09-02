/*
二叉树的深度优先遍历和广度优先遍历


*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
public:
    BinaryTreeNode():leftChild(nullptr),rightChild(nullptr){}
    BinaryTreeNode(int x):data(x),leftChild(nullptr),rightChild(nullptr){}
private:
    T data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

template<typename T>
class BinaryTree{
public:
    BinaryTree():Root(nullptr),TreeSize(0){}
    BinaryTree(BinaryTreeNode<T>& root):Root(root){}
    BinaryTree(BinaryTreeNode<T>& root,vector<T> vec):Root(root){
        inorderInsert(root,vec);
    }
    ~BinaryTree(){}
    bool empty() const {
        return TreeSize==0;
    }
    int size() const {
        return TreeSize;
    }
    void erase(){

    }
    int height() const {

    }
    void preOrder(){
        cout<<"前序遍历的结果为："<<endl;
        preOrder(Root);}
    void inOrder(){inOrder(Root);}
    void postOrder(){postOrder(Root);}
    void levelOrder(){levelOrder(Root);}
    void depthFirstSearch(){depthFirstSearch(Root);}
    void breadthFirstSearch(){breadthFirstSearch(Root);}
private:
    void preOrder(BinaryTreeNode<T> *root){
        if(root!=nullptr){
            cout<<root->data<<" ";
            preOrder(root->leftChild);
            preOrder(root->rightChild);
        }
    }
    void inOrder(BinaryTreeNode<T> *root){

    }
    void postOrder(BinaryTreeNode<T> *root){

    }
    void levelOrder(BinaryTreeNode<T> *root){

    }
    void depthFirstSearch(BinaryTreeNode<T> *root){

    }
    void breadthFirstSearch(BinaryTreeNode<T> *root){

    }
    void inorderInsert(BinaryTreeNode<T>& root,vector<T> vec){
        
    }
private:
    BinaryTreeNode<T>* Root;
    int TreeSize;
};





//深度优先遍历
void depthFirstSearch(Tree root){
    stack<Node*> nodeStack;  
    nodeStack.push(root);
    Node *node;
    while(!nodeStack.empty()){
        node = nodeStack.top();
        printf(format, node->data);  //遍历根结点
        nodeStack.pop();
        if(node->rchild){
            nodeStack.push(node->rchild);  //先将右子树压栈
        }
        if(node->lchild){
            nodeStack.push(node->lchild);  //再将左子树压栈
        }
    }
}
 
//广度优先遍历
void breadthFirstSearch(Tree root){
    queue<Node *> nodeQueue;  //使用C++的STL标准模板库
    nodeQueue.push(root);
    Node *node;
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        printf(format, node->data);
        if(node->lchild){
            nodeQueue.push(node->lchild);  //先将左子树入队
        }
        if(node->rchild){
            nodeQueue.push(node->rchild);  //再将右子树入队
        }
    }
}


int main() {
    char data[15] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    Tree tree;
    treeNodeConstructor(tree, data);
    printf("深度优先遍历二叉树结果: ");
    depthFirstSearch(tree);
    printf("\n\n广度优先遍历二叉树结果: ");
    breadthFirstSearch(tree);
    return 0;
}