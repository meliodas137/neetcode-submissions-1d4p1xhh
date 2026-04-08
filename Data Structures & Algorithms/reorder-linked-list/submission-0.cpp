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

    ListNode* reverse(ListNode* node){
        if(node == NULL || node->next == NULL) return node;
        
        ListNode* prev = NULL;

        while (node != NULL) {
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }

        return prev;
    }

    ListNode* merged(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        l1->next = merged(l2, l1->next);
        return l1;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;

        auto slow = head;
        auto fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto temp = slow->next;
        slow->next = NULL;
        
        slow = reverse(temp);

        head = merged(head, slow);
    }
};
