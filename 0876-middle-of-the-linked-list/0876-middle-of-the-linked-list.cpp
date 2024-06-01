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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* temp=head;
        int c=0;
        while(temp)
        {
            c++;
            temp=temp->next;
        }
        if(c%2!=0)
        c=(c+1)/2;
        else
        c=(c+2)/2;
        temp=head;
        for(int i=1;i<c;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
};