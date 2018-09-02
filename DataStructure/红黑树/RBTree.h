#ifndef RBTREE_H
#define RBTREE_H
#include<iostream>
#include<iomanip>
using namespace std;

enum RBTColor{ RED , BLACK };

template<typename T>
class RBTNode 
{
public:
    RBTNode(){}; //默认构造函数
    RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):key(value),color(c),parent(p),left(l),right(r){}
public:
    T key;            //节点关键字
    RBTColor color;   //节点颜色
    RBTNode *parent;  //父节点
    RBTNode *left;    //左孩子
    RBTNode *right;   //右孩子
};

template<typename T>
class RBTree
{
public: //外部接口
    RBTree():Root(nullptr){} //默认构造函数
    ~RBTree(); //默认析构函数
    void preOrder(); //前序遍历的外部接口
    void inOrder(); //中序遍历的外部接口
    void postOrder(); //后序遍历的外部接口
    RBTNode<T>* search(T key); //非递归实现的查找关键字为key的节点
    RBTNode<T>* iterativeSearch(T key);//递归实现的查找
    T minimum(); //查找最小节点，返回最小节点的关键字
    T maximum(); //查找最大节点，返回最大节点的关键字
    RBTNode<T>* successor(RBTNode<T> *x); //寻找节点x的后继节点（关键字大于该节点的最小节点）
    RBTNode<T>* predecessor(RBTNode<T> *x); //寻找节点x的前驱节点（关键字小于该节点的最小节点）
    void insert(T key); //插入节点，关键字key
    void remove(T key); //删除关键字为key的节点
    void destroy(); //销毁红黑树
    void print(); //打印红黑树

private: //内部接口
    void preOrder(RBTNode<T> *tree) const; //前序遍历的内部实现函数
    void inOrder(RBTNode<T> *tree) const; //中序遍历的内部实现函数
    void postOrder(RBTNode<T> *tree) const; //后序遍历的内部实现函数
    RBTNode<T>* search(RBTNode<T>* x,T key) const; //非递归search的内部实现函数
    RBTNode<T>* iterativeSearch(RBTNode<T>* x,T key) const; //递归iterativeSearch的内部实现函数
    RBTNode<T>* minimum(RBTNode<T> *tree); //minimum的内部实现函数
    RBTNode<T>* maximum(RBTNode<T> *tree); //maximum的内部实现函数
    void insert(RBTNode<T>* &root,RBTNode<T>* node); //insert的内部实现函数
    void remove(RBTNode<T>* &root,RBTNode<T> *node); //remove的内部实现函数
    void destroy(RBTNode<T>* &tree); //destroy的内部实现函数
    void print(RBTNode<T> *tree,T key,int direction); //print的内部实现函数
    void leftRotate(RBTNode<T>* &root,RBTNode<T>* x); //左旋
    void rightRotate(RBTNode<T>* &root,RBTNode<T>* x); //右旋
    void insertFixUp(RBTNode<T>* &root,RBTNode<T>* node); //插入修正函数
    void removeFixUp(RBTNode<T>* &root,RBTNode<T>* node,RBTNode<T>* parent); //删除修正函数

private:
    RBTNode<T> *Root;   //根结点

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)

};

// #include"RBTree.h"

template<typename T>
RBTree<T>::~RBTree() //默认析构函数
{
    destroy();
}

template<typename T>
void RBTree<T>::preOrder() //前序遍历
{
    preOrder(Root); //调用preOrder的内部实现函数
}
    
template<typename T>
void RBTree<T>::inOrder() //中序遍历
{
    inOrder(Root); //调用inOrder的内部实现函数
}

template<typename T>
void RBTree<T>::postOrder() //后序便利
{
    postOrder(Root); //调用postOrder的内部实现函数
}

template<typename T>
RBTNode<T>* RBTree<T>::search(T key) //非递归实现的查找关键字为key的节点
{
    search(Root,key); //调用非递归search的内部实现函数
}

template<typename T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key) //递归实现的查找
{
    iterativeSearch(Root,key); //调用递归iterativeSearch的内部实现函数
}

template<typename T>
T RBTree<T>::minimum() //查找最小节点，返回最小节点的关键字
{
    RBTNode<T> *p = minimum(Root); //调用minimum的内部实现函数
    if(p!=nullptr)
        return p->key;
    return (T)0;
}

template<typename T>
T RBTree<T>::maximum() //查找最大节点，返回最大节点的关键字
{
    RBTNode<T> *p = maximum(Root); //调用maximum的内部实现函数
    if(p!=nullptr)
        return p->key;
    return (T)0;
}

template<typename T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x) //寻找节点x的后继节点（关键字大于该节点的最小节点）
{
    if(x->right!=nullptr) //如果x有右孩子，就找出右孩子子树中的最小节点
        return minimum(x->right);
    RBTNode<T> *y=x->parent; //如果x是左孩子，那么直接返回y，也就是x的父节点
    while(y!=nullptr && x==y->right) //x没有右孩子并且x是父节点的右孩子，那么找出有左孩子的最低父节点
    {
        x=y;
        y=y->parent;
    }
    return y;
}

template<typename T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x) //寻找节点x的前驱节点（关键字小于该节点的最小节点）
{
    if(x->left!=nullptr) //如果x有左孩子，就找出左孩子子树中的最大节点
        return maximum(x->left);
    RBTNode<T> *y=x->parent; //如果x是右孩子，那么直接返回y，也就是x的父节点  
    while(y!=nullptr && x==y->left) //x没有左孩子并且x是父节点的左孩子，那么找出有右孩子的最低父节点
    {
        x=y;
        y=y->parent;
    }
    return y;
}

template<typename T>
void RBTree<T>::insert(T key) //插入节点，关键字key
{
    RBTNode<T> *z=new RBTNode<T>(key,BLACK,nullptr,nullptr,nullptr);

    // if((z=new RBTNode<T>(key,BLACK,nullptr,nullptr,nullptr)) ==0)//如果新建节点失败，就返回
    //     return;
    insert(Root,z); //调用insert内部实现函数
}

template<typename T>
void RBTree<T>::remove(T key) //删除关键字为key的节点
{
    RBTNode<T> *node; 
    if ((node = search(Root, key)) != NULL)
        remove(Root, node); //调用remove的内部实现函数
}

template<typename T>
void RBTree<T>::destroy() //销毁红黑树
{
    destroy(Root); //调用destroy的内部实现函数
}

template<typename T>
void RBTree<T>::print() //打印红黑树
{
    if(Root!=nullptr)
        print(Root,Root->key,0); //调用print的内部实现函数
}

template<typename T>
void RBTree<T>::preOrder(RBTNode<T> *tree) const //前序遍历的内部实现函数
{
    if(tree!=nullptr)   //前序遍历：根左右
    {
        cout<<tree->key<<" ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template<typename T>
void RBTree<T>::inOrder(RBTNode<T> *tree) const //中序遍历的内部实现函数
{
    if(tree!=nullptr)   //中序遍历：左根右
    {
        inOrder(tree->left);
        cout<<tree->key<<" ";
        inOrder(tree->right);
    }
}

template<typename T>
void RBTree<T>::postOrder(RBTNode<T> *tree) const //后序遍历的内部实现函数
{
    if(tree!=nullptr)   //后序遍历：左右根
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<<tree->key<<" ";
    }
}

template<typename T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const //非递归search的内部实现函数
{
    while(x!=nullptr && x->key!=key)
    {
        // if(key<x->key)
        //     x=x->left;
        // else
        //     x=x->right;
        x= key<x->key ? x->left : x->right;
    }
    return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const //递归iterativeSearch的内部实现函数
{
    if(x==nullptr || x->key==key)
        return x;
    // if(key<x->key)
    //     return search(x->left,key);
    // else
    //     return search(x->right,key);
    return key<x->key ? search(x->left,key) : search(x->right,key);
}

template<typename T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree) //minimum的内部实现函数
{
    if(tree==nullptr)
        return nullptr;
    while(tree->left!=nullptr) //最左就是最小
        tree=tree->left;
    return tree;
}

template<typename T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree) //maximum的内部实现函数
{
    if(tree==nullptr)
        return nullptr;
    while(tree->right!=nullptr) //最右就是最大
        tree=tree->right;
    return tree;
}

template<typename T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x) // 左旋
{
    RBTNode<T> *y=x->right;
    x->right=y->left;
    if(y->left!=nullptr)
        y->left->parent=x;
    y->parent=x->parent;
    if(x->parent==nullptr)
        root=y;
    else 
    {
        if(x->parent->left==x)
            x->parent->left=y;
        else
            x->parent->right=y;
    }
    y->left=x;
    x->parent=y;
}

template<typename T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y) // 右旋
{
    RBTNode<T> *x=y->left;
    y->left=x->right;
    if(x->right!=nullptr)
        x->right->parent=y;
    x->parent=y->parent;
    if(y->parent==nullptr)
        root=x;
    else 
    {
        if(y->parent->right==y)
            y->parent->right=x;
        else
            y->parent->left=x;
    }
    x->right=y;
    y->parent=x;
}
// 插入函数
template<typename T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node) //insert的内部实现函数
{
    RBTNode<T> *y=nullptr;
    RBTNode<T> *x=root;
    //第一步：二叉搜索树的插入操作
    while(x!=nullptr)
    {
        y=x;
        // if(node->key<x->key)
        //     x=x->key;
        // else
        //     x=x->right;
        x= (node->key<x->key) ? x->left : x->right;
    }
    node->parent=y;
    if(y!=nullptr)
    {
        if(node->key<y->key)
            y->left=node;
        else   
            y->right=node;
    }
    else
        root=node;//如果y是空节点，也就是说这棵树是空树，那么直接把新插入的节点变为根
    //第二步：新插入节点涂红色
    node->color=RED;
    //第三步：有问题就修正
    insertFixUp(root,node);
}

template<typename T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node) //插入修正函数
{
    RBTNode<T> *parent=nullptr; //父节点
    RBTNode<T> *gparent=nullptr; //祖父节点
    while((parent=rb_parent(node)) && rb_is_red(parent)) //需要插入修正的情况下，父节点一定是红色
    {
        gparent=rb_parent(parent);
        if(parent==gparent->left) //若父节点是祖父节点的左孩子
        {
            RBTNode<T> *uncle=gparent->right;
            //case1:叔节点是红色
            if(uncle && rb_is_red(uncle))
            {
                rb_set_black(uncle);
                rb_set_black(parent);
                rb_set_red(gparent);
                node=gparent;
                continue;
            }           
            //case2:叔节点是黑色，且当前节点是右孩子
            if(parent->right==node)
            {
                RBTNode<T> *tmp;
                leftRotate(root,parent);
                tmp=parent;
                parent=node;
                node=tmp;
            }//case2结束就进入case3
            //case3:叔节点是黑色，且当前孩子是左孩子
            rb_set_black(parent);
            rb_set_red(gparent);
            rightRotate(root,gparent);
        }
        else //若父节点是祖父节点的右孩子
        {
            RBTNode<T> *uncle=gparent->left;
            //case1:叔节点是红色
            if(uncle && rb_is_red(uncle))
            {
                rb_set_black(parent);
                rb_set_black(uncle);
                rb_set_red(gparent);
                node=gparent;
                continue;
            }
            //case2:叔节点是黑色，且当前节点是左孩子
            if(parent->left==node)
            {
                RBTNode<T> *tmp;
                rightRotate(root,parent);
                tmp=parent;
                parent=node;
                node=tmp;
            }
            //case3:叔叔是黑色，且当前节点是右孩子
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root,gparent);
        }
    }
    rb_set_black(root);//将根涂黑
}

template<typename T>
void RBTree<T>::remove(RBTNode<T>* &root, RBTNode<T> *node) //remove的内部实现函数
{
    RBTNode<T> *child=nullptr;
    RBTNode<T> *parent=nullptr;
    RBTColor color;
    //情况一：被删除的节点左右孩子都非空,实际上删除的其实是replace节点
    if(node->left!=nullptr && node->right!=nullptr) 
    {
        RBTNode<T> *replace=node; //被删除节点的后继节点，成为取代节点，用它来取代被删节点的位置，然后再将被删节点去掉
        //获取后继节点，也就是被删除节点的右子树中最左边的节点
        replace=replace->right;
        while(replace->left!=nullptr)
            replace=replace->left;
        if(rb_parent(node)) //node存在父节点，也就是说node不是根结点
        {
            if(rb_parent(node)->left==node)
                rb_parent(node)->left=replace;
            else
                rb_parent(node)->right=replace;
        }
        else //node不存在父节点，就更新根结点
            root=replace;
        child=replace->right; //取代节点已经是最左的节点，不存在左孩子，child是取代节点的右孩子
        parent=rb_parent(replace);
        color=rb_color(replace); //保存取代节点的颜色,实际上删除的其实是replace节点
        if(parent==node) //如果删除节点是取代节点的父节点
            parent=replace;
        else
        {
            if(child) //把replace节点从原来的位置删除，将replace的右孩子与父节点连接
                rb_set_parent(child,parent);
            parent->left=child;
            replace->right=node->right;
            rb_set_parent(node->right,replace);
        }
        replace->parent=node->parent;
        replace->color=node->color;
        replace->left=node->left; //把node节点的左孩子与replace节点连接
        node->left->parent=replace;
        if(color==BLACK) //被删除的节点颜色是黑色才会出现问题
            removeFixUp(root,child,parent);
        delete node;
        node=nullptr;
        return ;
    }
    //情况二：被删除的节点的左右孩子中有一个为空,这时删除的就是这个节点
    if(node->left!=nullptr)
        child=node->left;
    else
        child=node->right;
    parent=node->parent;
    color=node->color;
    if(child)
        child->parent=parent; //把被删除节点的孩子节点与被删除节点的父节点连接起来
    if(parent)
    {
        if(parent->left==node)
            parent->left=child;
        else
            parent->right=child;
    }
    else //如果被删除节点没有父节点，也就是说被删除节点是根结点，那就更新根结点
        root=child;
    if(color==BLACK) //被删除的节点颜色是黑色才会出现问题
        removeFixUp(root,child,parent);
    delete node;
    node=nullptr;
}

template<typename T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent) //删除修正函数
{
    RBTNode<T> *other=nullptr;
    while((!node || rb_is_black(node)) && node!=root) //当前节点是黑，并且不是根结点
    {
        if(parent->left==node) //当前节点是父节点的左孩子
        {
            other=parent->right; //other是兄弟节点
            //case1:兄弟节点是红色
            if(rb_is_red(other)) 
            {
                rb_set_black(other);
                rb_set_red(parent);
                leftRotate(root,parent);
                other=parent->right; //更新兄弟节点，是原来兄弟节点的右子节点
            }
            //case2:兄弟节点是黑色，且兄弟节点的两个子节点都是黑的
            if((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_red(other->right)))
            {
                rb_set_red(other); //兄弟节点变红
                node=parent; //父节点变为新的当前节点
                parent=rb_parent(node);
            }
            else
            {
                //case3:兄弟节点是黑色，兄弟节点的右孩子是黑，左孩子是红
                if(!other->right || rb_is_black(other->right))
                {
                    rb_set_black(other->left);
                    rb_set_red(other);
                    rightRotate(root,other);
                    other=parent->right;
                }//case3之后就成为case4的情况
                //case4:兄弟节点是黑色，兄弟节点的右孩子是红色，左孩子任意
                rb_set_color(other,rb_color(parent)); //兄弟变红
                rb_set_black(parent);
                rb_set_black(other->right);
                leftRotate(root,parent);
                node=root;
                break;
            }
        }
        else //当前节点是父节点的右孩子，与上述情况相反
        {
            other=parent->left; //other是兄弟节点
            //case1:兄弟节点是红色
            if(rb_is_red(other)) 
            {
                rb_set_black(other);
                rb_set_red(parent);
                leftRotate(root,parent);
                other=parent->left; //更新兄弟节点，是原来兄弟节点的右子节点
            }
            //case2:兄弟节点是黑色，且兄弟节点的两个子节点都是黑的
            if((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_red(other->right)))
            {
                rb_set_red(other); //兄弟节点变红
                node=parent; //父节点变为新的当前节点
                parent=rb_parent(node);
            }
            else
            {
                //case3:兄弟节点是黑色，兄弟节点的右孩子是黑，左孩子是红
                if(!other->left || rb_is_black(other->left))
                {
                    rb_set_black(other->right);
                    rb_set_red(other);
                    rightRotate(root,other);
                    other=parent->left;
                }//case3之后就成为case4的情况
                //case4:兄弟节点是黑色，兄弟节点的左孩子是红色，右孩子任意
                rb_set_color(other,rb_color(parent)); //兄弟变红
                rb_set_black(parent);
                rb_set_black(other->left);
                leftRotate(root,parent);
                node=root;
                break;
            }
        }
    }
    if(node) //如果当前节点是红或者当前节点是根节点，那么就直接把当前节点染黑就行
        rb_set_black(node);
}

template<typename T>
void RBTree<T>::destroy(RBTNode<T>* &tree) //destroy的内部实现函数
{
    if(tree==nullptr)
        return;
    if(tree->left!=nullptr)
        return destroy(tree->left);
    if(tree->right!=nullptr)
        return destroy(tree->right);
    delete tree;
    tree=nullptr;
}

template<typename T>
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction) //print的内部实现函数
{
    if(tree!=nullptr)
    {
        if(direction==0)
            cout<<setw(2)<<tree->key<<"(B) is root"<<endl;
        else
            cout<<setw(2)<<tree->key<<(rb_is_red(tree) ? "(R)" : "(B)")<<" is "
                <<setw(2)<<key<<"'s "<<setw(12)<<(direction==1 ? "right child" : "left child")<<endl;
        print(tree->left,tree->key,-1);
        print(tree->right,tree->key,1);
    }
}

#endif