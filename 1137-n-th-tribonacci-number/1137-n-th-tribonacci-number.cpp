class Solution {
public:

    int func(int n,int a,int b,int c,int i)
    {
        if(i==n-1)
        return c;
        return func(n,b,c,a+b+c,i+1);
        
    }


    int tribonacci(int n) 
    {
        int s=0; 
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        return func(n,0,1,1,1); 
    }
};