// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

// 示例:

// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 分治，不停的对半划分
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i{0}; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
    // LeetCode_21_合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        ListNode *p1 = l1; // 不破坏传入的指针
        ListNode *p2 = l2; 
        while(p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        cur->next = p1 ? p1 : p2;
        return dummy->next;
    }
};

// 最小堆，首先把k个链表的首元素都加入最小堆中，它们会自动排好序。
// 然后每次取出最小的那个元素加入最终链表中，然后把取出元素的下一个元素再加入堆中，
// 下次仍从堆中取出最小的元素做相同的操作，以此类推，直到堆中没有元素了，
// 此时k个链表也合并为了一个链表，返回首节点即可
class Solution {
private:
    struct cmp {
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q; // 最小堆
        for (int i{0}, sz = lists.size(); i < sz; ++i) {
            if (lists[i]) q.push(lists[i]); // 把所有链表头节点存入最小堆中
        }
        ListNode *head = nullptr;
        ListNode *pre = nullptr;
        ListNode *tmp = nullptr;
        while (!q.empty()) {
            tmp = q.top(); // 堆顶最小
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }
};