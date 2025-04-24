class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        set<int> st(nums.begin(),nums.end());

        int el=st.size();
        int c=0,re=0;
        int l=0,r=0;
        int n=nums.size();
        vector<int> hm(20001,0);

        while(r<n)
        {
            if(hm[nums[r]]==0)
            c++;
            hm[nums[r]]++;

            while(c==el)
            {
                re+=n-r;
                hm[nums[l]]--;
                
                if(hm[nums[l]]==0)
                c--;

                l++;
            }
            r++;
        }  
        return re;  
    }
};