// 题目描述
// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：
/*
时间复杂度为O（n），两个指针，一个在前面，另一个紧邻着这个指针，在后面。
两个指针同时向前移动，每移动一次，前面的指针的next指向NULL。
也就是说：访问过的节点都断开，最后到达的那个节点一定是尾节点的下一个，
也就是循环的第一个。
这时候已经是第二次访问循环的第一节点了，第一次访问的时候我们已经让它指向了NULL，
所以到这结束。
*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead->next)
            return NULL;
        ListNode* previous = pHead;
        ListNode* front = pHead ->next;
        while (front)
        {
            previous->next = NULL;
            previous = front;
            front = front->next;
        }
        return previous;
    }
};

//先说个定理：两个指针一个fast、一个slow同时从一个链表的头部出发
//fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
         if(pHead==NULL)return NULL;
         //先计算环中结点的个数
         //快慢指针相遇结点一定在环中
         ListNode *pFast=pHead,*pSlow=pHead->next;
         while(pFast!=NULL&&pSlow!=NULL&&pFast!=pSlow){
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
                pFast=pFast->next;
         }
         //开始统计环结点数
         int countNum=1;
         ListNode *pTempNode=pFast->next;
         if(pFast==pSlow&&pFast!=NULL){
             while(pTempNode!=pFast){
                 pTempNode=pTempNode->next;
                 ++countNum;
             }
         }
         else
             return NULL;
         //再设两指针，一先一后
         ListNode *pNode1=pHead,*pNode2=pHead;
         for(int i=0;i<countNum;i++){
                pNode1=pNode1->next;
         }
         while(pNode1!=pNode2){
             pNode1=pNode1->next;
             pNode2=pNode2->next;
         }
         return pNode1;
          
    }
};