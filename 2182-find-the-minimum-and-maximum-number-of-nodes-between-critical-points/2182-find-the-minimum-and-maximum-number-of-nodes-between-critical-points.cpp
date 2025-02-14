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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> re;
        int l=1;
        vector<int> v(2,-1);

        ListNode* prev=head;
        ListNode* cur=head->next;

        while(cur)
        {
            ListNode* nxt=cur->next;
            l++;
            if(nxt) 
            {
                if((prev->val > cur->val && nxt->val > cur->val) ||
                   (prev->val < cur->val && nxt->val < cur->val))
                    re.push_back(l);
            }
            prev=cur;
            cur=nxt;
        }

        if(re.size() < 2 || l<=3)
        return v;
   
        sort(re.begin(),re.end());
        int minDist = INT_MAX;
        
        // Find minimum distance between adjacent critical points
        for(int i = 1; i < re.size(); i++) {
            minDist = min(minDist, re[i] - re[i-1]);
        }
        
        v[0] = minDist;
        v[1] = re.back() - re[0];  // Maximum distance

        return v;
    }
};