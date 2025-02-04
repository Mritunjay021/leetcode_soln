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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
        return head;

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* dummy=NULL;
        int sz=0;

        while(curr && sz<k)
        {
            sz++;
            curr=curr->next;
        }

        curr=head;

        if(sz==k)
        {
            sz=0;
            while(curr && sz<k)
            {
                dummy=curr->next;
                curr->next=prev;
                prev=curr;
                curr=dummy;
                sz++;
            }
        }        
        else
        prev=head;

        if(dummy!=NULL)
        head->next=reverseKGroup(dummy,k);
        return prev;
    }
};