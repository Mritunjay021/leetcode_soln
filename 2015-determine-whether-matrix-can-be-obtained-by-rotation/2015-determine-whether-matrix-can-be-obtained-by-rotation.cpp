class Solution {
public:

    bool func2(vector<vector<int>>& mt,vector<vector<int>>& tgt)
    {
        int m=mt.size(),n=mt[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mt[i][j]!=tgt[i][j])
                return 0;
            }
        }
        return 1;
    }

    void func1(vector<vector<int>>& mt)
    {
        int m=mt.size(),n=mt[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j)
                swap(mt[i][j],mt[j][i]);
            }
        }    

        for(auto& it:mt)
        {
            reverse(it.begin(),it.end());
        }
    }

    bool findRotation(vector<vector<int>>& mt, vector<vector<int>>& tgt) 
    {
        for(int i=0;i<4;i++)
        {
            if(func2(mt,tgt))
            return 1;
            func1(mt);
        }
        return 0;
    }
};