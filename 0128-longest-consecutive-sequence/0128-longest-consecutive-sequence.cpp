class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
        return 0;
        
        set<int> st;

        for(auto it:nums)
        st.insert(it);

        int mx=-1,c=1;

        int x=*st.begin();

        for(auto it:st)
        {
            if(x+1==it)
            {
                c++;
                x=it;
            }
            else
            {
                mx=max(mx,c);
                c=1;
                x=it;
            }
        }

        mx=max(mx,c);

        return mx;
    }
};