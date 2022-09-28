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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !n)
            return head;
        if(!head->next && n == 1)
            return head->next;
        auto front = head;
        while(n--) {
            front = front->next;
        }
        auto ans = head;
        ListNode* prev = NULL;
        while(front) {
            prev = head;
            head = head->next;
            front = front->next;
        }
        if(!prev) return ans->next;
        prev->next = head->next;
        return ans;
    }
};























