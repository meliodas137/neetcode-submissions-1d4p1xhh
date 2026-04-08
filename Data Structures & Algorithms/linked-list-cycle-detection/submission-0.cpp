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
    bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL) return false;
        auto slow = head;
        auto fast = head->next;

        while (slow != NULL && fast != NULL && slow != fast) {
            slow = slow->next;
            if(fast->next != NULL) fast = fast->next->next;
            else fast = NULL;
        }

        if (slow != NULL && fast != NULL) return true;
        return false;
    }
};
