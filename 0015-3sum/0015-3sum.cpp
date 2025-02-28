class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {
            int f=i+1,l=nums.size()-1;
            while(f<l)
            {
                if(nums[i]+nums[f]+nums[l]==0)
                {
                    st.insert({nums[i],nums[f],nums[l]});
                    f++;
                    l--;
                }
                else if(nums[i]+nums[f]+nums[l]>0)
                l--;
                else
                f++;
            }
        }

        vector<vector<int>> v(st.begin(),st.end());

        

        return v;
    }
};