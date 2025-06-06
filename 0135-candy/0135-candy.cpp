class Solution {
public:
    int candy(vector<int>& rating) 
    {
        int n=rating.size();
        vector<int> candi(n,1);

        for(int i=1;i<n;i++)
        {
            if(rating[i]>rating[i-1])
            candi[i]=candi[i-1]+1;
        }    

        for(int j=n-2;j>=0;j--)
        {
            if(rating[j]>rating[j+1])
            candi[j]=max(candi[j],candi[j+1]+1);
        }

        int sum=0;
        for(auto it:candi)
        sum+=it;

        return sum;
    }
};