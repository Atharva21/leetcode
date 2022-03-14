/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void lst(Node* head) {
        while(head) {
            cout << head->val << " ";
            head = head -> next;
        }
        cout << endl;
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        auto temp = head;
        
        // lst(head);
        
        // first iter, copy.
        while(temp) {
            auto foo = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = foo;
            temp = foo;
        }
        
        // lst(head);
        
        // second iter, random ptrs
        temp = head;
        while(temp) {
            if(!temp->random) {
                temp->next->random = NULL;
            } else {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        // third iter, next ptrs
        
        auto ans = head->next;
        
        temp = head;
        while(temp) {
            auto nxtTemp = temp->next->next;
            temp->next->next = nxtTemp ? nxtTemp->next : NULL;
            temp->next = nxtTemp;
            temp = nxtTemp;
        }
        
        // lst(head);
        
        return ans;
    }
};