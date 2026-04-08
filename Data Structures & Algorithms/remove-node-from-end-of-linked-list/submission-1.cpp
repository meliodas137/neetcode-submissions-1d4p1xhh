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
        if(head == NULL) return head;
        
        auto fast = head->next;
        auto slow = head;
        for(int i = 1; i < n; i++) fast = fast->next;
        if(fast == NULL) return slow->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        if(slow->next == NULL) return NULL;
        slow->next = slow->next->next;

        return head;
    }
};
