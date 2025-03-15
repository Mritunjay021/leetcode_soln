class Solution {
public:

    bool func(vector<int>& nums,vector<vector<int>>& q,int b)
    {
        int n=nums.size();
        vector<int> v(n+1,0);

        for(int i=0;i<b;i++)
        {
            int l=q[i][0];
            int r=q[i][1];
            v[l]+=q[i][2];
            v[r+1]-=q[i][2]; 
        }

        for(int j=1;j<n;j++)
        v[j]+=v[j-1];

        for(int j=0;j<n;j++)
        {
            if(v[j]<nums[j])
            return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) 
    {
        int l=0,r=q.size();

        if(!func(nums,q,r))
        return -1;

        while(l<=r)
        {
            int mid=(l+r)/2;
            bool re=func(nums,q,mid);
            if(re)
            r=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
};