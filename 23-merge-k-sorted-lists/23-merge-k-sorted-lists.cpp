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
private:
    bool allNull(vector<ListNode*> lists) {
        for(auto& l: lists) if(l) return false;
        return true;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL, *temp=NULL;
        const int k = lists.size();
        while(!allNull(lists)) {
            int idx = -1;
            for(int i=0;i<k;++i) {
                auto node = lists[i];
                if(!node) continue;
                if(idx == -1 || node->val < lists[idx]->val) {
                    idx = i;
                }
            }
            if(!head) {
                temp = head = new ListNode(lists[idx]->val);
            } else {
                temp->next = new ListNode(lists[idx]->val);
                temp = temp->next;
            }
            lists[idx] = lists[idx]->next;
        }
        return head;
    }
};