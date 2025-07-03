class Solution {
public:

    int count_ones(int n)
    {
        int re=0;
        while(n)
        {
            n=n&(n-1);
            re++;
        }
        return re;
    }

    char kthCharacter(int k) 
    {
        return 'a'+count_ones(k-1);
    }
};