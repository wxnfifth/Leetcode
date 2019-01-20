/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* p = head;
        ListNode* pre = nullptr;
        while (p != nullptr) {
            ListNode* tmp = p;
            p = p->next;
            tmp->next = pre;
            pre = tmp;
        }
        return pre;
    }
public:
    ListNode* plusOne(ListNode* head) {
        //reverse list, plus one and reverse back
        ListNode* new_head = reverse(head);
        ListNode* p = new_head;
        p->val++;
        while (p->next != nullptr) {
            if (p->val >= 10) {
                p->val -= 10;
                p->next->val++;
            }
            p = p->next;
        }
        if (p->val >= 10) {
            p->val -= 10;
            p->next = new ListNode(1);
        }
        return reverse(new_head);
    }
};
