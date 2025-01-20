class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) 
    {
        int n1=m.size(),n2=m[0].size();
        vector<vector<int>> mat(n2,vector<int>(n1));
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<m[0].size();j++)
            {
                mat[j][i]=m[i][j];
            }
        }    
        return mat;
    }
};