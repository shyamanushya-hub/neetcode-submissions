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
        ListNode* fast = head;
        while(n && fast){
            fast = fast->next;
            n--;
        }

        if(!fast) {
            head = head->next;
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        while(fast){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;

        return head;
    }
};
