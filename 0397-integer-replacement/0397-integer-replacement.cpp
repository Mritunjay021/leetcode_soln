class Solution {
public:

    int integerReplacementLong(long long n) {
        if (n <= 1)
            return 0;
            
        if (n % 2 == 0)
            return 1 + integerReplacementLong(n / 2);
        else
            return 1 + min(integerReplacementLong(n + 1), 
                         integerReplacementLong(n - 1));
    }

    int integerReplacement(int n) 
    {
        return integerReplacementLong((long long)n);

    }
};