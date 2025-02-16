class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long b) {
        int i = 0, j = 0;

        int n = ct.size();
        long long s = 0;  
        int k = 0;

        deque<int> dq;    

        while(i < n) 
        {
            while(!dq.empty() && ct[dq.back()] <= ct[i]) 
            {
                dq.pop_back();
            }

            dq.push_back(i);
            s += rc[i];

             while(j <= i) 
             {
                while(!dq.empty() && dq.front() < j) 
                {
                    dq.pop_front();
                }
                
                if(dq.empty() || (ct[dq.front()] + (i-j+1)*s) <= b) 
                {
                    break;
                }
                
                s -= rc[j];
                j++;
            }

            k = max(k, i-j+1);
            i++;  
        }
        return k;
    }
};