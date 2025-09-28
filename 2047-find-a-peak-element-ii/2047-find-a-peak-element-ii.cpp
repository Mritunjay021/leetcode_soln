class Solution {
public:

    int func(vector<vector<int>>& mat,int col)
    {
        int mxval=-1,re=0;
        for(int i=0;i<mat.size();i++)
        {
            if(mxval < mat[i][col])
            {
                mxval=mat[i][col];
                re=i;
            }
        }
        return re;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int r=mat.size();
        int c=mat[0].size();

        int l=0,h=c-1;

        while(l<=h)
        {
            int m=(l+h)/2;
            int mxr=func(mat,m);

            int lt=m>0?mat[mxr][m-1]:-1;
            int rt=m<c-1?mat[mxr][m+1]:-1;

            if(mat[mxr][m] > lt && mat[mxr][m] > rt)
            return {mxr,m};

            if(mat[mxr][m] < lt)
            h=m-1;
            else
            l=m+1;
        }    

        return {-1,-1};
    }
};