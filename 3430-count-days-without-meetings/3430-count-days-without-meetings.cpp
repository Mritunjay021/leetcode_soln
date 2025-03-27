class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) 
    {
        sort(meet.begin(), meet.end());

        int s = 0, e = 0;
        vector<vector<int>> v;

        for (int i = 0; i < meet.size(); i++) 
        {
            if (s == 0 && e == 0) 
            {
                s = meet[i][0];
                e = meet[i][1];
                continue;
            }

            if (e < meet[i][0]) 
            { 
                v.push_back({s, e});
                s = meet[i][0], e = meet[i][1]; 
            } 
            else 
            {
                e = max(e, meet[i][1]); 
            }
        }

        v.push_back({s, e}); 

        int sm = v[0][0] - 1;

        for (int i = 1; i < v.size(); i++) {
            sm += v[i][0] - v[i - 1][1] - 1;
        }

        sm += max(0, days - v.back()[1]); 

        return sm; 
    }
};
