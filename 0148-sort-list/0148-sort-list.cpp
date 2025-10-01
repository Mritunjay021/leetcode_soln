/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* midfunc(ListNode* head)
    {
        ListNode* s=head;
        ListNode* f=head->next;

        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }

        return s;
    }

    ListNode* merge(ListNode* lft,ListNode* rt)
    {
        ListNode dummy;
        ListNode* temp= &dummy;

        while(lft && rt)
        {
            if(lft->val <= rt->val)
            {
                temp->next=lft;
                lft=lft->next;
            }
            else
            {
                temp->next=rt;
                rt=rt->next;
            }
            temp=temp->next;
        }

        if(lft)
        temp->next=lft;

        if(rt)
        temp->next=rt;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
        return head;

        ListNode* mid=midfunc(head);
        ListNode* rt=sortList(mid->next);
        mid->next=nullptr;
        

        ListNode* lft=sortList(head);
        

        return merge(lft,rt);   
    }
};