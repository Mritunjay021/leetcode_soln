// class Solution {
// public:

//     int func(vector<int>& nums,int m)
//     {
//         int s=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             s+=ceil(nums[i]/m);
//         }
//         return s;
//     }

//     int smallestDivisor(vector<int>& nums, int t) 
//     {
//         int l=*min_element(nums.begin(),nums.end());
//         int u=*max_element(nums.begin(),nums.end());
//         int ans=0;

//         while(l<=u)
//         {
//             int m=(l+u)/2;
//             int re=func(nums,m);

//             if(t<re)
//             {
//                 ans=m;
//                 l=m+1;
//             }
//             else
//             u=m-1;
//         }    
//         return ans;
//     }
// };


class Solution {
public:

    int func(vector<int>& nums, int m) 
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            s += (nums[i] + m - 1) / m; 
        }
        return s;
    }

    int smallestDivisor(vector<int>& nums, int t) 
    {
        int l = 1; 
        int u = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (l <= u) 
        {
            int m = l + (u - l) / 2; 
            int re = func(nums, m);

            if (re <= t) 
            {
                ans = m; 
                u = m - 1; 
            } 
            else 
            {
                l = m + 1; 
            }
        }    
        return ans;
    }
};
