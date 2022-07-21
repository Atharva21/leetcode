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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return NULL;
        if(left == right) return head;
        ListNode *node = head, *leftNode = NULL, *rightNode = NULL, *leftPrev = NULL, *rightNext = NULL, *prev=NULL;
        int i = 1;
        while(node) {
            if(i < left) {
                ++i;
                leftPrev = node;
                node = node->next;
                continue;
            }
            if(i == left) {
                prev = node;
                leftNode = node;
                ++i;
                node = node->next;
                continue;
            }
            if(i <= right) {
                auto nxt = node->next;
                if(i == right) {
                    rightNode = node;
                    rightNext = nxt;
                }
                node->next = prev;
                prev = node;
                node = nxt;
                ++i;
                continue;
            }
            break;
        }
        if(!leftPrev) {
            // left was head.
            leftNode -> next = rightNext;
            return rightNode;
        }
        leftPrev -> next = rightNode;
        leftNode -> next = rightNext;
        return head;
    }
};