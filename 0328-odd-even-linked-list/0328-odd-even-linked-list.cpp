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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next || !head->next->next)
        return head;
        
        ListNode* p1=head;
        ListNode* p2=head->next;

        ListNode* h2=p2;

        while(p1->next && p2->next)
        {
            p1->next=p1->next->next;
                p1=p1->next;

            p2->next=p2->next->next;
                p2=p2->next;
        }       
        p1->next=h2;
        return head;
    }
};