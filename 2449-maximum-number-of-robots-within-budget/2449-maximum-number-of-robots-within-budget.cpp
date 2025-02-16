class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        deque<int> dq;
        int l = 0;
        int n = runningCosts.size();
        long long runningSum = 0;
        int maxRobots = 0;

        for(int r = 0; r < n; r++){
            while(!dq.empty() && chargeTimes[dq.back()] < chargeTimes[r]){
                dq.pop_back();
            }
            dq.push_back(r);

            runningSum += runningCosts[r];
            //int expense = chargeTimes[dq.front()] + (r - l + 1) * runningSum;
            long long expense = chargeTimes[dq.front()] + (long long)(r - l + 1) * runningSum;

            if(expense > budget){
                runningSum -= runningCosts[l];
                if(dq.front() == l) dq.pop_front();
                l++;
            }

            maxRobots = max(maxRobots, r - l + 1);
        }
        return maxRobots;
    }
};