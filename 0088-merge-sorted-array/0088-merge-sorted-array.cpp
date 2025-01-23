class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i=m-1,j=n-1;
        int sz=nums1.size()-1;

        if(m==0)
        {
            copy(nums2.begin(),nums2.end(),nums1.begin());
            return;
        }

        if(n==0)
        return;

        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[sz]=nums1[i];
                i--;
            }
            else
            {
                nums1[sz]=nums2[j];
                j--;
            }
            sz--;
        }  

        while (j >= 0) {
            nums1[sz] = nums2[j];
            j--;
            sz--;
        }  
    }
};