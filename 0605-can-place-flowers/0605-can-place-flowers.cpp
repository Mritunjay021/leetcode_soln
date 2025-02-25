class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) 
    {
        if(!n)
        return 1;

        if(arr.size()==1)
        {
            if(arr[0]==0)
            return 1;
            else
            return 0;
        }
        
        int lf=-1;
        
        for(int i=0;i<arr.size();i++) 
        {
            if(arr[i]==1)
            lf=i;
            else
            {
                if(i==0 && arr[1]!=1)
                {
                    lf=0;
                    n--;
                    continue;
                }

                if(i-lf>1)
                {
                    if(i+1==arr.size())
                    {
                        n--;
                        continue;
                    }
                    if(i+1<arr.size() && arr[i+1]!=1)
                    {
                        lf=i;
                        n--;
                    }
                }
            }
        }   
        return n<=0;
    }
};