/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *lessHead = NULL, *lessLast = NULL;
        ListNode *greaterHead = NULL, *greaterLast = NULL;
        auto cur = head;
        
        while(cur) {
            auto nxt = cur->next;
            cur->next = NULL;
            if(cur->val < x) {
                if(!lessHead) {
                    lessHead = lessLast = cur;
                } else {
                    lessLast = lessLast->next = cur;
                }
            } else {
                if(!greaterHead) {
                    greaterHead = greaterLast = cur;
                } else {
                    greaterLast = greaterLast->next = cur;
                }
            }
            cur = nxt;
        }        
        
        if(!lessHead) {
            return greaterHead;
        }
        lessLast->next = greaterHead;
        return lessHead;
    }
};