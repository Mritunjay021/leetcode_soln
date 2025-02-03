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
    Node* flatten(Node* head) {
        Node* curr = head;
        
        while(curr != nullptr) 
        {
            if(curr->child != nullptr) 
            {
                Node* next=curr->next;
                Node* child = flatten(curr->child);

                curr->next=child;
                child->prev=curr;

                Node * tail=child;
                while(tail->next)
                {
                    tail=tail->next;
                }
                if(next)
                {
                    tail->next=next;
                    next->prev=tail;
                }
                curr->child=nullptr;
            }
            curr = curr->next;
        }
        
        return head;
    }
};