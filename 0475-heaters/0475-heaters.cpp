class Solution {
public:
    int findRadius(vector<int>& hs, vector<int>& ht) 
    {
        sort(ht.begin(),ht.end());
        sort(hs.begin(),hs.end());
        
        int m=hs.size();
        int n=ht.size();

        int mx=0;
        int j=0;

        for(int i=0;i<m;i++)
        {
            while(j<n-1 && abs(ht[j]-hs[i])>=abs(ht[j+1]-hs[i]))
            {
                j++;
            }
            mx=max(mx,abs(ht[j]-hs[i]));
        }

        return mx;
            
    }
};