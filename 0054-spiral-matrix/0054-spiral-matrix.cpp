class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) 
    {
        int n=mt.size();
        int m=mt[0].size();
        
        int t=0,b=n-1;
        int l=0,r=m-1;

        vector<int> ans;

        while(l<=r && t<=b)
        {
            //right
            for(int i=l;i<=r;i++)
            ans.push_back(mt[t][i]);
            t++;

            for(int i=t;i<=b;i++)
            ans.push_back(mt[i][r]);
            r--;

            if(t<=b)
            {
                for(int i=r;i>=l;i--)
                ans.push_back(mt[b][i]);
                b--;
            }

            if(l<=r)
            {
                for(int i=b;i>=t;i--)
                ans.push_back(mt[i][l]);
                l++;
            }
        }
        return ans;
    }
};