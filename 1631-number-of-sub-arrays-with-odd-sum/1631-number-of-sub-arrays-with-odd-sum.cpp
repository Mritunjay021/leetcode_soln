class Solution {
public:

    int numOfSubarrays(vector<int>& arr) 
    {    
        long long o=0,s=0;
        for(auto it:arr)
        {
            s+=it;
            o+=s%2;
        }
        o+=(arr.size()-o)*o;
        return o%1000000007;
        
    }
};