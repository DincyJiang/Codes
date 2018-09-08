/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 利用快慢指针找到链表的中点，慢指针移动的过程中把每个值入栈，后半段的值与栈中元素依次比较，相同就弹出，不同就返回false
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next){   // 头节点是空或者只有一个头节点，返回true
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        vector<int> vec; // 用vector做栈
        vec.push_back(slow->val);
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            vec.push_back(slow->val);
        }
        if (!fast->next){   // 如果链表节点总数是奇数个，那么就把中间的那个节点弹出来，不参与下面的比较
            vec.pop_back();
        }
        while (slow->next){
            slow = slow->next;
            if (vec.back() != slow->val){
                return false;
            }
            vec.pop_back();
        }
        return true;
    }
};

// 这道题的Follow Up让我们用O(1)的空间，那就是说我们不能使用stack了，
// 那么如果代替stack的作用呢，用stack的目的是为了利用其后进先出的特点，
// 好倒着取出前半段的元素。那么现在我们不用stack了，如何倒着取元素呢。
// 我们可以在找到中点后，将后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) // 头节点为空或者只有一个头节点
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next;
        ListNode *pre = head;
        while (last->next != nullptr) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next != nullptr) {
            slow = slow->next;
            if (pre->val != slow->val)
                return false;
            pre = pre->next;
        }
        return true;
    }
};