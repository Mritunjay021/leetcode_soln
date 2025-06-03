class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        stack<int> st;
        int op=0;

        for(int num:nums)
        {
            while(!st.empty() && st.top()>num)
            st.pop();
            if(st.empty() || st.top()<num)
            {
                if(num>0)
                op++;
                st.push(num);
            }
            
        }
        return op;
    }
};