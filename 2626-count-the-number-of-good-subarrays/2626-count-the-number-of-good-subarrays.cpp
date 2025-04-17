class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        long long l=0,r=0;
        long long n=nums.size();
        unordered_map<long long,long long> mp;
        long long gp=0,c=0;
        
        while(l<n)
        {
            while(r<n && c<k)
            {
                mp[nums[r]]++;

                if(mp[nums[r]]>=2)
                c+=mp[nums[r]]-1;

                r++;
            }

            if(c>=k)
            gp+=n-r+1;

            mp[nums[l]]--;

            if(mp[nums[l]]>0)
            c-=mp[nums[l]];

            l++;
        }
        return gp;
    }
};