////ħ��ʦ��������
////����������
////ħ��ʦ������A��2��3����J��Q��Kʮ���ź����˿��ơ��ڱ���ħ��ǰ��ħ��ʦ�Ѿ������ǰ���һ����˳����źã��л�ɫ��һ�泯�£���
////ħ�����ݹ���Ϊ��һ��ʼ��ħ��ʦ��1��Ȼ���������������Ʒ��������Ǻ���A��Ȼ����ŵ������ϣ�
////�ڶ���,ħ��ʦ��1��2������һ���Ʒŵ���Щ�Ƶ������棬���ڶ����Ʒ�ת�����������Ǻ���2��
////�����Σ�ħ��ʦ��1��2��3������1��2�������ηŵ���Щ�Ƶ������棬���������Ʒ����������Ǻ���3��
////����ֱ�������е��ƶ�������Ϊֹ����ԭ���Ƶ�˳������εġ�
////�𰸣�1 8 2 5 10 3 12 11 9 4 7 6 13
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
////��ʼ��һ��ѭ������
//void InitLinkList(LinkList &L, int n)
//{
//    L = new Node;
//    L->next = L;
//    LinkList p;
//    for(int j = 0; j < n; ++j)
//    {
//        p = new Node;
//        p->data = 0;          //��ʼֵΪ��
//        p->next = L->next;    //�½ڵ�ָ��ԭ���ĵ�һ���ڵ�
//        L->next = p;          //ͷ�ڵ�ָ���µĽڵ�
//    }
//}
//
//void Magician(LinkList &L, int n)
//{
//    LinkList p = L->next;
//    p->data = 1;                       //��һ������1
//    for(int num = 2; num <= n; ++num)  //�����ҵ�2-n�Ƶ�λ��
//    {
//        int i = 0;
//        while(i < num)
//        {
//            p = p->next;
//            if(p->data == 0) ++i;      //��λ������Ӧ������
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
