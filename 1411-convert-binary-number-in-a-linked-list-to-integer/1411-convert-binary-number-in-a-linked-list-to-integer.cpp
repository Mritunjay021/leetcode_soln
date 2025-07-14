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
    int getDecimalValue(ListNode* head) 
    {
        if(!head)
        return 0;

        string s="";

        while(head)
        {
            s+=(head->val+'0');
            head=head->next;
        }    

        int num=0;

        int n=s.length();

        for(int i=0;i<s.length();i++)
        {
            num+=(s[i]-'0')*pow(2,n-i-1);
        }

        return num;
    }
};