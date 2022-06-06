/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        stack<ListNode*> s1, s2;
        ListNode *t1 = h1, *t2 = h2;
        while(t1) {
            s1.push(t1);
            t1 = t1->next;
        }
        while(t2) {
            s2.push(t2);
            t2 = t2->next;
        }
        ListNode* ans = NULL;
        while(!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
            ans = s1.top();
            s1.pop();
            s2.pop();
        }
        return ans;
    }
};