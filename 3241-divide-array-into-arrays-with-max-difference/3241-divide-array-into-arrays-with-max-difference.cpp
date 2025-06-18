class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n=nums.size();

        sort(nums.begin(),nums.end()); 
        vector<vector<int>> vec;  

        for(int i=0;i<n-2;i+=3)
        {
            if(nums[i+2]-nums[i]>k)
            return {};

            vec.push_back({nums[i],nums[i+1],nums[i+2]});
        }    

        // for(int i=0;i<n/3;i++)
        // {
        //     if(vec[i][2]-vec[i][0]>k)
        //     return {};
        // }
        return vec;
    }
};