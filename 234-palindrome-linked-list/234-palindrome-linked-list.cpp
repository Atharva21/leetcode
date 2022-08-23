class Solution {
    ListNode* getMiddle(ListNode* head) {
        ListNode *fast = head,*slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head, ListNode* previous) {
        if(head == nullptr) return previous;
        ListNode* nxt = head->next;
        head->next = previous;
        return reverse(nxt, head);
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMiddle(head);
        mid = reverse(mid, nullptr);
        while(mid != nullptr) {
            if(head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};