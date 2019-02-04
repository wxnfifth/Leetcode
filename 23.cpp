/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct Node{
        ListNode* l;
        int id = 0;
        bool operator<(const Node& o) const {
            return l->val > o.l->val;
        }
        Node(ListNode* _l, int _id) {
            l = _l;
            id = _id;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        vector<ListNode*> heads(lists);
        for (int i = 0; i < heads.size(); ++i) {
            if (heads[i] != nullptr) {
                q.push(Node(heads[i], i));
            }
        }
        ListNode* ans = nullptr;
        ListNode* p = nullptr;
        while (!q.empty()) {
            Node n = q.top();
            q.pop();
            if (ans == nullptr) {
                ans = n.l;
                p = n.l;
                heads[n.id] = n.l->next;
                if (heads[n.id] != nullptr) {
                    q.push(Node(heads[n.id], n.id));
                }
            } else {
                p->next = n.l;
                p = p->next;
                heads[n.id] = n.l->next;
                if (heads[n.id] != nullptr) {
                    q.push(Node(heads[n.id], n.id));
                }
            }
        }
        
        return ans;
    }
};
