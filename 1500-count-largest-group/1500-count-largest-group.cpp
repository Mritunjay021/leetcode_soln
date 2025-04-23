class Solution {
public:
    int countLargestGroup(int n) 
    {
        unordered_map<int,int> mp;

        for(int i=1;i<=n;i++)
        {
            int s=0,j=i;
            while(j)
            {
                s+=j%10;
                j=j/10;
            }
            mp[s]++;
        }

        int mx=INT_MIN,c=0;

        for(auto it:mp)
        {
            if(mp[it.first]>mx)
            {
                mx=mp[it.first];
                c=1;
            }
            else if(mp[it.first]==mx)
            c++;
        }

        return c;
    }
};