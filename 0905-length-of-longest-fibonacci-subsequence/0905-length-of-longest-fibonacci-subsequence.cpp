class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_set<int> st(arr.begin(),arr.end());
        int mx=0;

        for(int i=0;i<n;i++) 
        {
            for(int j=i+1;j<n;j++)
            {
                int prev=arr[j];
                int curr=arr[j]+arr[i];
                int l=2;
                while(st.find(curr)!=st.end())
                {
                    int temp=curr;
                    curr+=prev;
                    prev=temp;
                    l++;
                }
                if(l>2)
                mx=max(mx,l);
            }
        }  
        return mx; 
    }
};