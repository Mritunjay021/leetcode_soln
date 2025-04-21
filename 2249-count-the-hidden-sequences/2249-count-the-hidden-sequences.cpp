class Solution {
public:
    int numberOfArrays(vector<int>& diff, int low, int up) 
    {
        long long mn=0,mx=0,el=0;
        long long n=diff.size();
        
        for(int i=0;i<n;i++)
        {
            el+=diff[i];
            mn=min(mn,el);
            mx=max(mx,el);
        }  

        int r=mx-mn;

        return up-low+1-r>0?up-low+1-r:0;  
    }
};