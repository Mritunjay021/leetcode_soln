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
    void reorderList(ListNode* head) 
    {
        stack<ListNode*> st;
        int l=0;

        ListNode* temp=head;

        while(temp)
        {
            st.push(temp);
            temp=temp->next;
            l++;
        }    
        l=(l-1)/2;

        temp=head;
        while(l--)
        {
            ListNode* sd=temp->next;
            ListNode* tp=st.top();
            st.pop();
            temp->next=tp;
            tp->next=sd;
            temp=sd;
        }
        st.top()->next=nullptr;

    }
};