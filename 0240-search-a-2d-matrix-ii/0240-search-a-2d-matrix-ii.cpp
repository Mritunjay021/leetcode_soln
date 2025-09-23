class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tgt) 
    {
        int r=mat.size();
        int c=mat[0].size();

        int i=0,j=c-1;

        while(i<r && j>=0)
        {
            if(tgt == mat[i][j])
            return 1;

            if(tgt < mat[i][j])
            j--;
            else
            i++;
        }    

        return 0;
    }
};