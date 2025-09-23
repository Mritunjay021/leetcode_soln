class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& nums) 
    {
        int m=nums.size();
        int n=nums[0].size();

        // sort(nums.begin(),nums.end());

        int ind=0,c=0;

        for(int i=0;i<m;i++)
        {
            sort(nums[i].begin(),nums[i].end());
            int id=lower_bound(nums[i].begin(),nums[i].end(),1)-nums[i].begin();

            if(id==n)
            continue;

            if(n-id>c)
            {
                ind=i;
                c=n-id;
            }
        }    

        return {ind,c};
    }
};