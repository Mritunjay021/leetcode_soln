class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> v;
        if(nums.size()==1 && nums[0]==target)
        {
            v.push_back(0);
            v.push_back(0);
            return v;
        }
        int l=0,r=nums.size()-1,c=0,j;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target==nums[mid])
            {
                if(mid-1 >=0 && target==nums[mid-1])
                {
                    c++;j=mid-1;
                    while(j>=0 && target==nums[j]) j--;
                    v.push_back(j+1);
                }
                v.push_back(mid);
                l=mid+1;
            }
            else if(nums[mid]<target)
            l=mid+1;
            else
            r=mid-1;
        }   
        if(v.empty())
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        } 
        vector<int> ans;
        ans.push_back(v[0]);
        ans.push_back(v[v.size()-1]);
        return ans;
    }
};
