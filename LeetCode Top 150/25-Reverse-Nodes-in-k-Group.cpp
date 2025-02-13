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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *itr = head;
        for(int i = 1; i <= k; i++) {
            if(!itr) return head;
            itr = itr->next;
        }

        int cnt = 1;
        ListNode *prev, *curr, *temp;
        prev = temp = nullptr;
        curr = head;
        while(curr && cnt <= k) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }

        if(curr) 
           head->next = reverseKGroup(curr, k);
        return prev;
    }
};