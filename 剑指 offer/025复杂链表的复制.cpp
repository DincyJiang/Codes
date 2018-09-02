// 题目描述
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
// 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）



struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};


//思路一：递归，但是不通过
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        RandomListNode *pNewHead=new RandomListNode(pHead->label);
        pNewHead->next = pHead->next;
        pNewHead->random=pHead->random;
        pNewHead->next=Clone(pHead->next);
        return pNewHead;
    }
};

//思路二：三步法
//第一步：复制节点，每个节点接在原来节点后面
//第二步：复制随机节点，新节点的随机节点就在旧的节点的随机节点的下一个
//第三步，拆分出新的链表
//注意：
//头节点不能改变，一定要用新的指针指向头节点，不然这个链表头就再也回不去了

class Solution {
public:
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* newNode=pHead;
       
        while(newNode!=nullptr)
        {
            RandomListNode* pClone=new RandomListNode(0);
            pClone->label=newNode->label;
            pClone->next=newNode->next;
            pClone->random=nullptr;
            newNode->next=pClone;
            newNode=pClone->next;
        }
    }
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* newNode=pHead;
        while(newNode!=nullptr)
        {
            RandomListNode* pCloned=newNode->next;
            if(newNode->random!=NULL)
                pCloned->random=newNode->random->next;
            newNode=pCloned->next;
        }
    }
    RandomListNode* splitNewList(RandomListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        RandomListNode* newNode=pHead;
        RandomListNode* newListHead=newNode->next;
        RandomListNode* newListNode=newNode->next;
        newNode->next=newListNode->next;
        newNode=newNode->next;
        while(newNode!=nullptr)
        {
            newListNode->next=newNode->next;
            newListNode=newListNode->next;
            newNode->next=newListNode->next;
            newNode=newNode->next;
        }
        return newListHead;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return splitNewList(pHead);
    }
};

#include<unorderd_map>
//思路三：哈希表法
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(!pHead) return nullptr;
        //定义一个哈希表
        unordered_multimap<RandomListNode*,RandomListNode*> table;
        // 开辟一个头结点
        RandomListNode* pClonedHead=new RandomListNode(pHead->label);
        pClonedHead->next=nullptr;
        pClonedHead->random=nullptr;
        // 将头结点放入map中
        table.insert(make_pair(pHead,pClonedHead));
        //设置操作指针
        RandomListNode* pNode=pHead->next;
        RandomListNode* pClonedNode=pClonedHead;
        // 第一遍先将简单链表复制一下
        while(pNode!=nullptr){
            // 不断开辟pNode的拷贝结点
            RandomListNode* pClonedTail=new RandomListNode(pNode->label);
            pClonedTail->next=nullptr;
            pClonedTail->random=nullptr;
            //连接新节点，更新当前节点
            pClonedNode->next=pClonedTail;
            pClonedNode=pClonedTail;
            //将对应关系  插入到哈希表中
            table.insert(make_pair(pNode,pClonedTail));
            //向后移动操作节点
            pNode=pNode->next;
        }
        //需从头开始设置random节点，设置操作指针
        pNode=pHead;
        pClonedNode=pClonedHead;
        // 根据map中保存的数据，找到对应的节点
        while(pNode!=NULL){
            if(pNode->random!=NULL) {
                pClonedNode->random=table.find(pNode->random)->second;//找到对应节点，更新复制链表
            }
            //向后移动操作节点
            pNode=pNode->next;
            pClonedNode=pClonedNode->next;
        }
        return pClonedHead;
    }
};

