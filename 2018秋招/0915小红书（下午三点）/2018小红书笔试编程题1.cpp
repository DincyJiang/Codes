/*
25. k个一组翻转链表
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
    ListNode *last = pre->next;
    ListNode *cur = last->next;
    while(cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1) return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *pre = dummy, *cur = head;
    dummy->next = head;
    int i = 0;
    while (cur) {
        ++i;
        if (i % k == 0) {
            pre = reverseOneGroup(pre, cur->next);
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}

ListNode* createList(vector<int> vec, int i, int n) {
    if (i == n-1) return nullptr;
    ListNode* head = new ListNode(vec[i]);
    head->next = createList(vec, i + 1, n);
    return head;
}

void printList(ListNode* head) {
    if (head == nullptr) return;
    cout << head->val << ' ';
    head = head->next;
    printList(head);
}

int main() {
    vector<int> vec ;
    vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(2);
    
    int i;
    // while (cin >> i)
    //     vec.push_back(i);
    int n = vec.size();
    int k = vec[n-1];
    ListNode* head = createList(vec, 0, n);

    printList(head);
    cout << endl;

    head = reverseKGroup(head, k);

    printList(head);
    cout << endl;

    return 0;
}