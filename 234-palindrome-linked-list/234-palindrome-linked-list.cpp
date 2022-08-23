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
    bool compare(ListNode* h1, ListNode* h2) {
        while(h1 && h2) {
            if(h1->val != h2->val)
                return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
    ListNode* reverseLinkedList(ListNode* head, ListNode* tail) {
        if(head == tail || !head) return head;
        // cout << head->val << " " << tail->val << endl;
        ListNode* prev = NULL;
        while(head != tail) {
            auto nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        tail->next = prev;
        // auto foo = tail;
        // while(foo) {
        //     cout << foo->val << " ";
        //     foo = foo->next;
        // }
        return tail;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)  return true;
        if(!head->next->next) {
            // just two nodes
            return head->val == head->next->val;
        }
        auto fast=head, slow=head;
        ListNode* prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) {
            // odd
            // cout << "odd" << endl;
            return compare(slow->next, reverseLinkedList(head, prev));
        } else {
            // even
            // cout << "even" << endl;
            return compare(slow, reverseLinkedList(head, prev));
        }
        return false;
    }
};