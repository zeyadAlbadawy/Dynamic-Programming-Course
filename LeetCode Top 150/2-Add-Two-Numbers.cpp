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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int tempSum = 0, carr = 0;
        
        while(l1 || l2 || carr) {
            if(l1 && l2) {
                tempSum = (l1->val + l2->val + carr);
                l1 = l1->next;
                l2 = l2->next;
            } else if(l1) {
                tempSum = (l1->val + carr);
                l1 = l1->next;
            } else if(l2) {
                tempSum = l2->val + carr;
                l2 = l2->next;
            } else if(carr) {
                tempSum = carr;
            }
            curr->next = new ListNode(tempSum  % 10);
            curr = curr->next; 
            carr = tempSum / 10;
        }
        return dummy->next;
    }
};