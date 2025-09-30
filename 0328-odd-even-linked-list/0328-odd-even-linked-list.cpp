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
        if(!head || (head && !head->next) || (head->next && !head->next->next))
        return head;

        ListNode* eh=head->next;

        ListNode* o=head;
        ListNode* e=head->next;

        while(o && e && o->next->next)
        {
            o->next=o->next->next;
            e->next=e->next->next;

            o=o->next;
            e=e->next;
        }
        o->next=eh;

        return head;
    }
};