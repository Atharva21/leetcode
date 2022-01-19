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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> vis;
        while(head != NULL && head -> next != NULL) {
            if(vis[head -> next]) return head -> next;
            vis[head] = true;
            head = head -> next;
        }
        return NULL;
    }
};







