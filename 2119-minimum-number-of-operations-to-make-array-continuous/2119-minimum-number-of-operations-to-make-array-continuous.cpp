class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int len=nums.size();
        sort(nums.begin(),nums.end());

        vector<int> st;

        st.push_back(nums[0]);
        for(int i=1;i<len;i++)
        {
            if(nums[i]!=nums[i-1])
            st.push_back(nums[i]);
        }

        int r=0;

        int res=len;

        for(int l=0;l<st.size();l++)
        {
            while(r<st.size() && st[r]<st[l]+len)
            r++;

            int win=r-l;

            res=min(res,len-win);
        }
        return res;

    }
};