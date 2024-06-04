class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {  
        int l=nums.size();
        vector<vector<int>> re;
        for(int i=0;i<(1<<l);i++)
        {
            vector<int> s;
            for(int j=0;j<l;j++)
            {
                if(i&(1<<j))
                s.push_back(nums[j]);
            }
            re.push_back(s);
        }
        return re;
    }
}; 
 