class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int re=0;
        for(auto it:nums)
        {
            int c=0;
            while(it)
            {
                c++;
                it/=10;
            }
            if(c%2==0)
            re++;
        }

        return re;
    }
};