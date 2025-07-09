class Solution {
public:
    int maxFreeTime(int endt, int k, vector<int>& st, vector<int>& et) 
    {
        vector<int> arr;

        arr.push_back(st[0]-0);

        int n=st.size();

        for(int i=1;i<n;i++)
        {
            arr.push_back(st[i]-et[i-1]);
        }

        arr.push_back(endt-et[n-1]);

        int i=0,j=0;
        int mx=0,cs=0;

        while(i<arr.size())
        {
            cs+=arr[i];

            while(i-j+1>k+1)
            {
                cs-=arr[j];
                j++;
            }

            mx=max(mx,cs);
            i++;
        }

        return mx;
    }
};