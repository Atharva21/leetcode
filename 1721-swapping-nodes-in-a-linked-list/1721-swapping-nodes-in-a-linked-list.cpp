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
    int getlen(ListNode* head) {
        int ans = 0;
        while(head) {
            head = head->next;
            ++ans;
        }
        return ans;
    }
    ListNode* forward(ListNode* head, int i) {
        while(i-- && head) {
            head = head->next;
        }
        return head;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        const int n = getlen(head);
        k -= 1;
        auto f = forward(head, k);
        auto s = forward(head, n-k-1);
        // cout << f->val << " " << s->val;
        swap(f->val, s->val);
        return head;
    }
};