// 题目描述
// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
{
    if( pHead == NULL ) return pHead;
 
    ListNode *pre = NULL; //指向前面最晚访问过的不重复结点
    ListNode *p = pHead; //指向当前处理的结点
    ListNode *q = NULL; //指向当前处理结点后面结点
 
    while( p != NULL )
    {
        //当前结点p，（其实是p指向当前结点），与它下一个结点p->next的val相同，说明要删掉有这个val的所有结点
        if( p->next != NULL && p->next->val == p->val )
        {
            q = p->next;
 
            //找到q，它指向最后一个与p val相同的结点，那p 到 q （包含） 都是要删除的
            while( q != NULL && q->next != NULL && q->next->val == p->val )
            {
                q = q->next;
            }
 
            //如果p指向链表中第一个元素，p -> ... -> q ->... , 要删除p到q, 将指向链表第一个元素的指针pHead指向q->next。
            if( p == pHead )
            {
                pHead = q->next;
            }
            else//如果p不指向链表中第一个元素，pre -> p ->...->q ->... ，要删除p到q，即pre->next = q->next
            {
                pre->next = q->next;
            }
            //当前处理的p要向链表尾部移动
            p = q->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return pHead;
}
 
};

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
          if(pHead==NULL||pHead->next==NULL) return pHead;
          else
          {
              //新建一个节点，防止头结点要被删除
              ListNode* newHead=new ListNode(-1);
              newHead->next=pHead;
              ListNode* pre=newHead;
              ListNode* p=pHead;
              ListNode* next=NULL;
              while(p!=NULL && p->next!=NULL)
              {
                  next=p->next;
                  if(p->val==next->val)//如果当前节点的值和下一个节点的值相等
                  {
                      while(next!=NULL && next->val==p->val)//向后重复查找
                          next=next->next;
                    pre->next=next;//指针赋值，就相当于删除
                    p=next;
                  }
                  else//如果当前节点和下一个节点值不等，则向后移动一位
                  {
                      pre=p;
                      p=p->next;
                  }
              }
           return newHead->next;//返回头结点的下一个节点
               
          }
    }
};