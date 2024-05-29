class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0 || x>INT_MAX)
        return false;
        else
        {
            int n = x , re = 0;
            while(x!=0)
            {
                if(re>INT_MAX/10)
                return false;
                else
                re = re*10 + (x%10);
                x = x/10; 
            }
            if(re==n)
            return true;
            else
            return false;
        }
    }
};