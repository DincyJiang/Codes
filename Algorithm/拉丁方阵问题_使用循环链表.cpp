////����������һ��n��n�ķ��󣬷�����ǡ��n�ֲ�ͬ��Ԫ�أ�ÿ��Ԫ��ǡ��n����
////����ÿ��Ԫ����һ�к�һ����ǡ�ó���һ�Ρ�������ѧ�Һ�����ѧ��ŷ��ʹ����
////����ĸ����Ϊ����������Ԫ�صķ��ţ�����������˶�������
////ʹ��ѭ���������������
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
////����һ����ʼ������ķ���
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
//    cout<<"��������Ҫ��������������Ĺ�ģ(����3*3������3����)"<<endl;
//    cin>>num;
//    p = ListCreate(num);
//    for(i = 0;i < num;i++)
//    {
//        q = p;
//        while(1)
//        {
//            cout<<p->data;
//            p = p ->next;
//            if(p == q)break;  //�Ѿ�����һ����
//        }
//        p = p ->next;
//        cout<<endl;
//    }
//    cout<<"���������ӡ���";
//    return 0;
//}
