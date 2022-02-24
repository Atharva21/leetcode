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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        while(head) {
            // cout << head -> val << " ";
            ans.push_back(head -> val);
            head = head -> next;
        }
        
        sort(ans.begin(), ans.end());
        ListNode *headAns = NULL, *temp = NULL;
        for(int i: ans) {
            if(!headAns) {
                temp = headAns = new ListNode(i);
            } else {
                temp -> next = new ListNode(i);
                temp = temp -> next;
            }
        }
        return headAns;
    }
};