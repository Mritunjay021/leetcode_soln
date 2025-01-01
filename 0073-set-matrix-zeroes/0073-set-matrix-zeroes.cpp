class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) 
    {
        set<int> r1, c1; 

        int r = mt.size();
        int c = mt[0].size();

        for (int i = 0; i < r; i++) 
        {
            for (int j = 0; j < c; j++) 
            {
                if (mt[i][j] == 0) 
                {
                    r1.emplace(i); 
                    c1.emplace(j); 
                }
            }
        }

        for (auto it : r1) 
        {
            for (int i = 0; i < c; i++)
                mt[it][i] = 0;
        }

        for (auto it : c1) 
        {
            for (int i = 0; i < r; i++)
                mt[i][it] = 0;
        }
    }
};
