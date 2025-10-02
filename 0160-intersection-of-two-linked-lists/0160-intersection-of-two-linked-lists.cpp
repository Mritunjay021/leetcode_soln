/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* func(ListNode* h1,ListNode* h2,int l1,int l2)
    {
        while(l1>l2)
        {
            h1=h1->next;
            l1--;
        }

        ListNode* s=h1;
        ListNode* f=h2;

        while(s!=f)
        {
            s=s->next;
            f=f->next;
        }

        return s;
    }

    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) 
    {
        ListNode* t1=ha;
        ListNode* t2=hb;

        int l1=0,l2=0;

        while(t1)
        {
            t1=t1->next;
            l1++;
        }

        while(t2)
        {
            t2=t2->next;
            l2++;
        }

        if(l1>l2)
        return func(ha,hb,l1,l2);
        else
        return func(hb,ha,l2,l1);
    }
};


        