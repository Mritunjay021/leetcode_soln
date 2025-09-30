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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(n==0)
        return head;

        ListNode* temp=head;
        int l=0;

        while(temp)
        {
            l++;
            temp=temp->next;
        }  

        if(l==1)
        return nullptr; 
        else if(l==n)
        return head->next; 

        temp=head;

        l-=n+1;

        while(l)
        {
            temp=temp->next;
            l--;
        }

        if(n==1)
        temp->next=NULL;
        else
        temp->next=temp->next->next;
        
        return head;
    }
};