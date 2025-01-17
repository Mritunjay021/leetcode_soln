class Solution {
public:
    int maxArea(vector<int>& arr) 
    {
        int mx=0;
        int l=0,r=arr.size()-1;
        while(l<r)
        {
            mx=max(mx,((r-l)*min(arr[r],arr[l])));
            if(arr[l]>arr[r])
            r--;
            else
            l++;
        }
        return mx;
    }
};