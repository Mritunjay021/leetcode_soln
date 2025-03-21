class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> re; 

        for (int i = 0; i < n; i++) 
        {
            vector<int> row(i + 1, 1); 
            for (int j = 1; j < i; j++) 
            {
                row[j] = re[i - 1][j - 1] + re[i - 1][j]; 
            }

            re.push_back(row); 
        }    
        return re;
    }
};