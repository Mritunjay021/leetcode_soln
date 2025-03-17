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
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* dummy=new ListNode(0,head);
        unordered_map<int,ListNode*> mp;
        int s=0;

        ListNode* temp=dummy;

        while(temp)
        {
            s+=temp->val;
            mp[s]=temp;

            temp=temp->next;
        }

        s=0;

        temp=dummy;

        while(temp)
        {
            s+=temp->val;
            temp->next=mp[s]->next;
            temp=temp->next;
        }

        return dummy->next;
    }
};