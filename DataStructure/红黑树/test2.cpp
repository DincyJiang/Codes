#include<iostream>
#include<vector>
#include"RBTree.h"
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(40);
    vec.push_back(30);
    vec.push_back(60);
    vec.push_back(90);
    vec.push_back(70);
    vec.push_back(20);
    vec.push_back(50);
    vec.push_back(80);
    int check_insert=1; //插入动作的检测开关（0:关闭；1:打开）
    int check_remove=1; //删除动作的检测开关（0:关闭；1:打开）
    RBTree<int> *tree=new RBTree<int>();
    cout<<"== 原始数据： ";
    for(auto i : vec)
        cout<<i<<" ";
    cout<<endl;
    for(auto i : vec)
    {
        tree->insert(i);
        // 设置check_insert=1,测试"添加函数"
        if(check_insert)
        {
            cout<<"== 添加节点："<<i<<endl;
            // cout<<"== 树的详细信息："<<endl;
            // tree->print();
            // cout<<endl;
        }
    }
    cout << "== 前序遍历：";
    tree->preOrder();
    cout << endl;
    cout << "== 中序遍历: ";
    tree->inOrder();
    cout << endl;
    cout << "== 后序遍历: ";
    tree->postOrder();
    cout << endl;
    cout << "== 最小值：" << tree->minimum() << endl;
    cout << "== 最大值：" << tree->maximum() << endl;
    cout << "== 树的详细信息：" <<endl;
    tree->print();
    if(check_remove)
    {
        for(auto i : vec)
        {
            tree->remove(i);
            cout<<"== 删除节点："<<i<<endl;
            cout<<"== 树的详细信息："<<endl;
            tree->print();
            cout<<endl;
        }
    }
    tree->destroy();
    return 0;
}