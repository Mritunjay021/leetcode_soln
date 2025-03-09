class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int l=0,r=1,c=0;

        while(l<arr.size())
        {
            if(arr[r%n]!=arr[(r-1)%n])
            r++;
            else
            {
                l=r;
                r++;
            }
            if(r-l==k)
            {
                l++;
                c++;
            }
        }  
        return c; 
    }
};