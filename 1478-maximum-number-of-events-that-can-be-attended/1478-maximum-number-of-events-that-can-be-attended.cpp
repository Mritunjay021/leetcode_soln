class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n=events.size();

        sort(events.begin(),events.end());

        priority_queue<int,vector<int>,greater<int>> pq;

        int i=0,c=0;
        int d=events[0][0];

        while(!pq.empty() || i<n)
        {
            if(pq.empty())
            d=events[i][0];

            while(i<n && events[i][0]==d)
            {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty())
            {
                pq.pop();
                c++;
            }

            d++;

            while(!pq.empty() && pq.top()<d)
            {
                pq.pop();
            }
        }   

        return c;
    }
};