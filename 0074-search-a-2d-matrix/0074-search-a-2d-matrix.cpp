class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tgt) 
    {
        int r=mat.size();
        int c=mat[0].size();
        
        if(tgt<mat[0][0] || tgt>mat[r-1][c-1])
        return 0;

        int l=0,h=r-1;

        if(r>1)
        {
            while(l<=h)
            {
                int m=(l+h)/2;

                if(mat[m][0] == tgt)
                return 1;

                if(mat[m][0]<tgt)
                l=m+1;
                else
                h=m-1;
            }
        } 
        
        int id=lower_bound(mat[h].begin(),mat[h].end(),tgt)-mat[h].begin();

        if(id==c)
        return 0;

        return  mat[h][id]==tgt;
    }
};