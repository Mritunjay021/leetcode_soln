class Solution {
public:

    int func(int m,vector<int>& arr,int k)
    {
        int prev=arr[0];
        k--;
        
        for(int i=1;i<arr.size();i++)
        {
            if(k==0)
            break;

            if(arr[i]-prev>=m)
            {
                k--;
                prev=arr[i];
            }
        }
        return k==0;
    }

    int maximumTastiness(vector<int>& p, int k) 
    {
        sort(p.begin(),p.end());
        int l=0,ans=0;
        int u=p[p.size()-1]-p[0];
        while(l<=u)
        {
            int m=(u+l)/2;

            if(func(m,p,k))
            {
                ans=m;
                l=m+1;
            }
            else
            u=m-1;
        }
        return ans;
    }
};