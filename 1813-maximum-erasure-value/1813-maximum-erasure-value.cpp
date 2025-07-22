class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int l=0,r=0,sm=0,mx=INT_MIN;
        int n=nums.size();

        set<int> st;

        while(r<n)
        {
            if(st.size()==0 || st.find(nums[r])==st.end())
            {
                st.insert(nums[r]);
                sm+=nums[r];
            }
            else 
            {
                while(nums[l]!=nums[r])
                {
                    sm-=nums[l];
                    st.erase(nums[l]);
                    l++;
                }
                l++;
            }

            mx=max(mx,sm);
            r++;
        }  

        return mx; 
    }
};