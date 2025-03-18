class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int l=0,mx=1,bits=0;

        for(int r=0;r<nums.size();r++)
        {
            while((nums[r]&bits) !=0)
            {
                bits^=nums[l];
                l++;
            }

            bits |= nums[r];
            mx=max(mx,r-l+1);
        }    
        return mx;
    }
};

// if two elements will give 0 it means that there 1 bits is totallly different so we will keeo the track of all the 1 bits  in used and if the bits is already in used we will shrink the window by removing the leftmost element bits 
// the key operations are 
//nums[r]&bits!=0 it checks if the bits of nums[r] is already in use
// bits^=nums[l] it removes the bits of the nums[l] element 
// bits|= nums[r] it adds the nums[r] elements bits into bits