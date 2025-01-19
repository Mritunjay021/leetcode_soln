class Solution {
public:

    int mod = 1000000007;

    int maxSum(vector<int>& n1, vector<int>& n2) 
    {
        int i = 0, j = 0;
        long long s1 = 0, s2 = 0, re = 0; 

        while (i < n1.size() && j < n2.size()) 
        {
            if (n1[i] < n2[j]) 
            s1+=n1[i++];
            else if (n2[j] < n1[i]) 
            s2+=n2[j++];
            else 
            {
                re = (re + max(s1, s2) + n1[i]) % mod; 
                i++; s1 = 0;
                j++; s2 = 0;
            }
        }

        while (i < n1.size()) 
        {
            s1 = (s1 + n1[i]);
            i++;
        }

        while (j < n2.size()) 
        {
            s2 = (s2 + n2[j]);
            j++;
        }

        return (re + max(s1, s2)) % mod;
    }
};
