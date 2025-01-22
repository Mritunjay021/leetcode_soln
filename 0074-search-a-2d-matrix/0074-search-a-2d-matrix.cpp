class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int t) 
    {
        int m = mt.size();
        int n = mt[0].size();

        // Step 1: Binary search to find the correct row
        int l = 0, u = m - 1, c = -1;

        while (l <= u)
        {
            int md = (l + u) / 2;
            if (mt[md][0] == t) // Target is at the start of the row
                return true;
            else if (mt[md][0] > t)
                u = md - 1;
            else
            {
                c = md; // Keep track of the potential row
                l = md + 1;
            }
        }

        // If the row index is invalid, return false
        if (c == -1)
            return false;

        // Step 2: Binary search within the selected row
        l = 0;
        u = n - 1;

        while (l <= u)
        {
            int md = (l + u) / 2;
            if (mt[c][md] == t) // Target found
                return true;
            else if (mt[c][md] > t)
                u = md - 1;
            else
                l = md + 1;
        }

        return false; // Target not found
    }
};
