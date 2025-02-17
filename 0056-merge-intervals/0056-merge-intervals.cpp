class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) 
    {
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;

        for(int i=0;i<arr.size();i++)
        {
            if(v.empty() || v.back()[1]<arr[i][0])
            {
                v.push_back(arr[i]);
            }
            else
            {
                if(arr[i][0]<=v.back()[1])
                v.back()[1]=max(arr[i][1],v.back()[1]);
            }
        }    

        return v;
    }
};