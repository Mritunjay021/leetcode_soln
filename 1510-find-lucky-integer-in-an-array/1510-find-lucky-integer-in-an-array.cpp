class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        vector<int> hash(500,0);

        for(int i:arr)
        {
            hash[i-1]++;
        }    

        int mx=-1;

        for(int i=1;i<501;i++)
        {
            if(hash[i-1]==i)
            mx=i;
        }

        return mx;
    }
};