class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        stack<int> st;

        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && st.top()>nums[i] && nums.size()-i-1>=k-st.size())
            {
                st.pop();
            }
            
            if(st.size()<k)
            st.push(nums[i]);
        }   

        cout<<st.size()<<endl; 

        vector<int> v;
        
        while (!st.empty()) 
        {
            v.push_back(st.top());
            st.pop();             
        }
        reverse(v.begin(), v.end());

        return v;
    }
};