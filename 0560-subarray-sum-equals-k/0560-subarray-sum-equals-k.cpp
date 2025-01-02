class Solution {
public:
    int subarraySum(vector<int>& arr, int k) 
    {
        unordered_map<long long,int> mp;
        mp[0]=1;
        
        int sm=0,mx=0;
        for(int i=0;i<arr.size();i++)
        {
            sm+=arr[i];
            int rem=sm-k;
            mx+=mp[rem];
            mp[sm]+=1;
            
        }
        return mx;
    }
};