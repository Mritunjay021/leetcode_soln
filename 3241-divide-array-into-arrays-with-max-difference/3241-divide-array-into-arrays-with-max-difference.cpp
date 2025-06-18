class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n=nums.size();

        sort(nums.begin(),nums.end()); 
        vector<int> v;
        vector<vector<int>> vec;  

        for(int i=0;i<n/3;i++)
        {
            for(int j=0;j<3;j++)
            {
                v.push_back(nums[i*3+j]);
            }
            vec.push_back(v);
            v.clear();
        }    

        vector<vector<int>> ep;        

        for(int i=0;i<n/3;i++)
        {
            if(vec[i][2]-vec[i][0]>k)
            return ep;
        }
        return vec;
    }
};