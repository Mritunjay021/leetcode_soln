/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) return nullptr;
        
        Node* tp=head;

        while(tp)
        {
            Node* node=new Node(tp->val);
            node->next=tp->next;
            tp->next=node;

            tp=node->next;
        }

        tp=head;
        Node* node=head->next;

        while(node->next)
        {
            node->random = tp->random ? tp->random->next : NULL;

            tp=node->next;
            node=tp->next;
        }

        node->random = tp->random ? tp->random->next : NULL;

        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        node=head;

        while (node) {
            copyCurr->next = node->next;
            node->next = node->next->next;

            node = node->next;
            copyCurr = copyCurr->next;
        }

        return dummy->next;
    }
};