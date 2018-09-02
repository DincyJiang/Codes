////魔术师发牌问题
////问题描述：
////魔术师手中有A、2、3……J、Q、K十三张黑桃扑克牌。在表演魔术前，魔术师已经将他们按照一定的顺序叠放好（有花色的一面朝下）。
////魔术表演过程为：一开始，魔术师数1，然后把最上面的那张牌翻过来，是黑桃A；然后将其放到桌面上；
////第二次,魔术师数1、2；将第一张牌放到这些牌的最下面，将第二张牌翻转过来，正好是黑桃2；
////第三次，魔术师数1、2、3；将第1、2张牌依次放到这些牌的最下面，将第三张牌翻过来正好是黑桃3；
////……直到将所有的牌都翻出来为止。问原来牌的顺序是如何的。
////答案：1 8 2 5 10 3 12 11 9 4 7 6 13
//
//#include <iostream>
//using namespace std;
//#define N 13
//
//typedef struct Node
//{
//    int data;
//    Node *next;
//}Node,*LinkList;
//
////初始化一个循环链表
//void InitLinkList(LinkList &L, int n)
//{
//    L = new Node;
//    L->next = L;
//    LinkList p;
//    for(int j = 0; j < n; ++j)
//    {
//        p = new Node;
//        p->data = 0;          //初始值为零
//        p->next = L->next;    //新节点指向原来的第一个节点
//        L->next = p;          //头节点指向新的节点
//    }
//}
//
//void Magician(LinkList &L, int n)
//{
//    LinkList p = L->next;
//    p->data = 1;                       //第一张牌是1
//    for(int num = 2; num <= n; ++num)  //依次找到2-n牌的位置
//    {
//        int i = 0;
//        while(i < num)
//        {
//            p = p->next;
//            if(p->data == 0) ++i;      //该位置有牌应该跳过
//        }
//        p->data = num;
//    }
//}
//
//void Print(LinkList &L)
//{
//    LinkList p = L->next;
//    cout << "The Sort is: ";
//    while(p != L)
//    {
//        cout << p->data << " ";
//        p = p->next;
//    }
//    cout << endl;
//}
//
//int main()
//{
//    LinkList L;
//    InitLinkList(L, N);
//    Magician(L, N);
//    Print(L);
//}
