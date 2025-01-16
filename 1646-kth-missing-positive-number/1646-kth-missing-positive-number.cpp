class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        // if(arr.size()==1)
        // {
        //     return arr[0]-1;
        // }
        
        int l=0,u=arr.size()-1;

        while(l<=u)
        {
            int m=(l+u)/2;

            if(arr[m]-(m+1)>=k)
            u=m-1;
            else
            l=m+1;
        }
        return k+u+1;
    }
};