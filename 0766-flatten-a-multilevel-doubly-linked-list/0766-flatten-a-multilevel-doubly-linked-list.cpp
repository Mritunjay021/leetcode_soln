/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* func(Node* head)
    {
        while(head->next)
        head=head->next;

        return head;
    }

    Node* flatten(Node* head) 
    {
        Node* curr=head;

        while(curr)
        {
            Node* next=curr->next;

            if(curr->child)
            {
                Node* chld=func(curr->child);
                curr->next=curr->child;
                curr->child->prev=curr;
                if(next)
                {
                    next->prev=chld;
                chld->next=next;
                }
                curr->child=NULL;
            }
            curr=curr->next;
        }   
        return  head;
    }
};