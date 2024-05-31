class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n==1)
        return true;
        else if(n==0)
        return false;
        else if(log2(n)==static_cast<int>(log2(n)))
        return true;
        else
        return false;    
    }
};