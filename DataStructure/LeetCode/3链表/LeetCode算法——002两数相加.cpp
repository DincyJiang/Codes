/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
// 一位一位加，考虑进位的问题
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(-1);
        result->next = nullptr;
        ListNode *current = result;
        int carry = 0;  // 进位
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            current->next = new ListNode(1);
        }
        return result->next;
    }
};


// 垃圾思路：数取出来，求和之后再分出去
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         vector<int> num1;
//         vector<int> num2;
//         num1.push_back(l1->val);
//         num2.push_back(l2->val);
//         while (l1->next != nullptr){
//             num1.push_back(l1->next->val);
//             l1 = l1->next;
//         }
//         while (l2->next != nullptr){
//             num1.push_back(l2->next->val);
//             l2 = l2->next;
//         }
//         int sum1;
//         for (int i = 0; i < num1.size(); ++i){
//             int j = 0;
//             while (j != i){
//                 num1[i] *= 10;
//                 ++j;
//             }
//             sum1 += num1[i];
//         }
//         int sum2;
//         for (int i = 0; i < num2.size(); ++i){
//             int j = 0;
//             while (j != i){
//                 num2[i] *= 10;
//                 ++j;
//             }
//             sum2 += num2[i];
//         }
//         int sum = sum1 + sum2;
//         vector<int> num;

//     }
// };