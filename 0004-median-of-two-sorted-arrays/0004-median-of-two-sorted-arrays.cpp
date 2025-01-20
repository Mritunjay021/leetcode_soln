class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) 
    {
        int m = n1.size(), n = n2.size();
        int i = 0, j = 0, k = 0;
        vector<int> re;

        while (i < m && j < n) 
        {
            if (n1[i] < n2[j]) 
                re.push_back(n1[i++]);
            else 
                re.push_back(n2[j++]);
        }

        while (i < m) 
            re.push_back(n1[i++]);

        while (j < n) 
            re.push_back(n2[j++]);

        int totalSize = m + n;
        if (totalSize % 2 == 1) 
        {
            return re[totalSize / 2];
        } 
        else 
        {
            return (re[totalSize / 2] + re[(totalSize / 2) - 1]) / 2.0;
        }
    }
};
