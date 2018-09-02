////拉丁方阵是一种n×n的方阵，方阵中恰有n种不同的元素，每种元素恰有n个，
////并且每种元素在一行和一列中恰好出现一次。著名数学家和物理学家欧拉使用拉
////丁字母来作为拉丁方阵里元素的符号，拉丁方阵因此而得名。
////使用循环链表来解决问题
//
//#include<iostream>
//using namespace std;
//
//typedef struct LNode
//{
//    int data;
//    struct LNode *next;
//}LNode;
//typedef struct LNode *LinkList;
//
////定义一个初始化链表的方法
//LinkList ListCreate(int n)
//{
//    LinkList head = NULL,p,q = head;
//    int i;
//    for(i = 1;i <= n;i++)
//    {
//        p = (LinkList)malloc(sizeof(LNode));
//        p ->data = i;
//        if(head == NULL)head = p;
//        else q ->next = p;
//        q = p;
//    }
//    q ->next = head;
//    return head;
//}
//
//int main()
//{
//    LinkList p,q;
//    int i,num = 0;
//    cout<<"请输入您要构建的拉丁方针的规模(比如3*3，输入3即可)"<<endl;
//    cin>>num;
//    p = ListCreate(num);
//    for(i = 0;i < num;i++)
//    {
//        q = p;
//        while(1)
//        {
//            cout<<p->data;
//            p = p ->next;
//            if(p == q)break;  //已经走完一轮了
//        }
//        p = p ->next;
//        cout<<endl;
//    }
//    cout<<"拉丁方阵打印完毕";
//    return 0;
//}
