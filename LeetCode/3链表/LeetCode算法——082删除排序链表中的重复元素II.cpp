/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 由于链表开头可能会有重复项，被删掉的话头指针会改变，而最终却还需要返回链表的头指针。
// 所以需要定义一个新的节点，然后链上原链表，然后定义一个前驱指针和一个现指针，
// 每当前驱指针指向新建的节点，现指针从下一个位置开始往下遍历，遇到相同的则继续往下，
// 直到遇到不同项时，把前驱指针的next指向下面那个不同的元素。
// 如果现指针遍历的第一个元素就不相同，则把前驱指针向下移一位。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        while (pre->next != nullptr) {
            ListNode *cur = pre->next;
            while (cur->next != nullptr && cur->next->val == cur->val)
                cur = cur->next;
            if (cur != pre->next) // 如果这个值的节点只有两个
                pre->next = cur->next;
            else // 没有重复的节点，就把pre后移一个
                pre = pre->next;
        }
        return dummy->next;
    }
};