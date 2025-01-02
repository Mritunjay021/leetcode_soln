class Solution {
public:
    void rotate(vector<vector<int>>& mt) 
    {
        int n=mt.size();
        for(int i=0;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                if(i!=j)
                swap(mt[i][j],mt[j][i]);
            }
        }    

        for(int i=0;i<n;i++)
        {
            reverse(mt[i].begin(),mt[i].end());
        }
    }
};