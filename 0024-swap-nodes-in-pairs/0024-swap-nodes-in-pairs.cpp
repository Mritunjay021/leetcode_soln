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
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head->next)
        return head;
        
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *curr = head;

        while(curr && curr->next)
        {
            ListNode* npn=curr->next->next;
            ListNode* nxt=curr->next;

            curr->next=npn;
            nxt->next=curr;
            prev->next=nxt;

            prev=curr;
            curr=npn;
        }  

        return dummy.next;

    }
};